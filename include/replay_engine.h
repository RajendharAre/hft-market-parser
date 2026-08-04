#pragma once

#include "itch_reader.h"
#include "itch_decoder.h"
#include "order_book.h"
#include "statistics.h"

class ReplayEngine
{
public:

    bool initialize(const std::string& filename);

    void replay(uint64_t maxMessages = 0);
private:

    ITCHReader reader;

    ITCHDecoder decoder;

   Statistics statistics;

   LimitOrderBook orderBook;
};
