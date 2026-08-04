#pragma once

#include <cstdint>

class Statistics
{
public:

    uint64_t systemEvents = 0;

    uint64_t stockDirectory = 0;

    uint64_t addOrders = 0;

    uint64_t executeOrders = 0;

    uint64_t unknownMessages = 0;

    uint64_t totalMessages = 0;

    uint64_t cancelOrders = 0;
};
