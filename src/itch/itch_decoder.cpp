#include "../../include/itch_decoder.h"
#include "../../include/itch_protocol.h"
#include "../../include/byte_utils.h"

#include <iostream>

void ITCHDecoder::decode(
    const std::vector<char>& message,
    Statistics& stats,
LimitOrderBook& book)
{
    if(message.empty())
        return;

    switch(message[0])
    {
        case 'S':
            decodeSystemEvent(message, stats);
            break;

        case 'R':
            decodeStockDirectory(message, stats);
            break;
	case 'A':
{
    stats.addOrders++;
    stats.totalMessages++;

    auto* msg =
        reinterpret_cast<const AddOrderMessage*>(message.data());

    book.handle_add(msg);

    break;
}
case 'E':
{
    stats.executeOrders++;
    stats.totalMessages++;

    auto* msg =
        reinterpret_cast<const OrderExecutedMessage*>(message.data());

    book.handle_execute(msg);

    break;
}
case 'X':
{
    stats.cancelOrders++;
    stats.totalMessages++;

    auto* msg =
        reinterpret_cast<const OrderCancelMessage*>(message.data());

    book.handle_cancel(msg);

    break;
}
	default:
    		stats.unknownMessages++;
    		stats.totalMessages++;
    		break;
    }
}


void ITCHDecoder::decodeSystemEvent(
    const std::vector<char>&,
    Statistics& stats)
{
    stats.systemEvents++;
    stats.totalMessages++;
}


void ITCHDecoder::decodeStockDirectory(const std::vector<char>&, Statistics& stats) {
	stats.stockDirectory++;
	stats.totalMessages++;
}

void ITCHDecoder::decodeAddOrder(const std::vector<char>&, Statistics& stats)
{
	stats.addOrders++;
	stats.totalMessages++;
}

void ITCHDecoder::decodeOrderCancel(
    const std::vector<char>&,
    Statistics& stats)
{
    stats.cancelOrders++;
    stats.totalMessages++;
}
