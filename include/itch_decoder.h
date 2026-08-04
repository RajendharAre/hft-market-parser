#pragma once

#include <vector>

#include "statistics.h"
#include "order_book.h"

class ITCHDecoder
{
public:

    void decode(
    const std::vector<char>& message,
    Statistics& stats,
    LimitOrderBook& book);

private:

    void decodeSystemEvent(
        const std::vector<char>& message,
        Statistics& stats);

    void decodeStockDirectory(
        const std::vector<char>& message,
        Statistics& stats);

    void decodeAddOrder(
        const std::vector<char>& message,
        Statistics& stats);
void decodeOrderCancel(
    const std::vector<char>&,
    Statistics&);
};
