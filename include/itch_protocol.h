#pragma once

#include <cstdint>

#pragma pack(push,1)

struct SystemEventMessage
{
    char type;

    uint16_t stockLocate;

    uint16_t trackingNumber;

    uint8_t timestamp[6];

    char eventCode;
};

struct StockDirectoryMessage
{
    char type;

    uint16_t stockLocate;

    uint16_t trackingNumber;

    uint8_t timestamp[6];

    char stock[8];

    char marketCategory;

    char financialStatusIndicator;

    uint32_t roundLotSize;

    char roundLotsOnly;
};

struct AddOrderMessage
{
    char type;

    uint16_t stockLocate;

    uint16_t trackingNumber;

    uint8_t timestamp[6];

    uint64_t orderReferenceNumber;

    char buySellIndicator;

    uint32_t shares;

    char stock[8];

    uint32_t price;
};

struct OrderExecutedMessage
{
    char type;

    uint16_t stockLocate;

    uint16_t trackingNumber;

    uint8_t timestamp[6];

    uint64_t orderReferenceNumber;

    uint32_t executedShares;

    uint64_t matchNumber;
};

struct OrderCancelMessage
{
    char type;

    uint16_t stockLocate;

    uint16_t trackingNumber;

    uint8_t timestamp[6];

    uint64_t orderReferenceNumber;

    uint32_t canceledShares;
};

#pragma pack(pop)
