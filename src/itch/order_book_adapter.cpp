#include "../../include/order_book_adapter.h"
#include "../../include/byte_utils.h"

#include <cstring>

OrderBookAdapter::OrderBookAdapter()
{
}

void OrderBookAdapter::handleAdd(const AddOrderMessage* msg)
{
    OrderAddMessage legacy{};

    legacy.order_id = msg->orderReferenceNumber;

    std::memcpy(
        legacy.symbol,
        msg->stock,
        8
    );

    legacy.shares = be32(msg->shares);

    legacy.price = be32(msg->price);

    orderBook.handle_add(&legacy);
}

size_t OrderBookAdapter::activeOrders() const
{
    return orderBook.get_total_active_orders();
}
