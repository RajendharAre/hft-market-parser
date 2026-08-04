#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include <unordered_map>
#include <cstdint>

#include "itch_protocol.h"
#include "byte_utils.h"

// Represents one active order in the book
struct OrderState
{
    uint64_t order_id;
    uint32_t shares;
    uint32_t price;
};

class LimitOrderBook
{
private:

    std::unordered_map<uint64_t, OrderState> order_repository;

public:

    LimitOrderBook()
    {
        // Reduce expensive rehash operations.
        // Tune this later based on measured active-order counts.
        order_repository.reserve(5000000);
    }

    //----------------------------------------------------------
    // Add Order (A)
    //----------------------------------------------------------
    inline void handle_add(const AddOrderMessage* msg)
    {
        const uint64_t orderId = be64(msg->orderReferenceNumber);

        order_repository[orderId] =
        {
            orderId,
            be32(msg->shares),
            be32(msg->price)
        };
    }

    //----------------------------------------------------------
    // Order Executed (E)
    //----------------------------------------------------------
    inline void handle_execute(const OrderExecutedMessage* msg)
    {
        const uint64_t orderId = be64(msg->orderReferenceNumber);

        auto it = order_repository.find(orderId);

        if (it == order_repository.end())
            return;

        const uint32_t executed = be32(msg->executedShares);

        if (executed >= it->second.shares)
        {
            order_repository.erase(it);
        }
        else
        {
            it->second.shares -= executed;
        }
    }

    //----------------------------------------------------------
    // Order Cancel (X)
    //----------------------------------------------------------
    inline void handle_cancel(const OrderCancelMessage* msg)
    {
        const uint64_t orderId = be64(msg->orderReferenceNumber);

        auto it = order_repository.find(orderId);

        if (it == order_repository.end())
            return;

        const uint32_t cancelled = be32(msg->canceledShares);

        if (cancelled >= it->second.shares)
        {
            order_repository.erase(it);
        }
        else
        {
            it->second.shares -= cancelled;
        }
    }

    //----------------------------------------------------------
    // Statistics
    //----------------------------------------------------------
    inline size_t get_total_active_orders() const
    {
        return order_repository.size();
    }

    inline void clear()
    {
        order_repository.clear();
    }
};

#endif
