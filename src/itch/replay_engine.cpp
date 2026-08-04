#include "../../include/replay_engine.h"

#include <chrono>
#include <iostream>

bool ReplayEngine::initialize(const std::string& filename)
{
    return reader.open(filename);
}

void ReplayEngine::replay(uint64_t maxMessages)
{
    auto start = std::chrono::high_resolution_clock::now();
	while(reader.next())
{
    if(maxMessages != 0 &&
       statistics.totalMessages >= maxMessages)
    {
        break;
    }

    decoder.decode(
        reader.data(),
        statistics,
        orderBook);

    if(statistics.totalMessages % 10000000 == 0)
    {
        std::cout
            << "Processed "
            << statistics.totalMessages
            << " messages\n";
    }
}
    auto end = std::chrono::high_resolution_clock::now();

double seconds =
    std::chrono::duration<double>(end - start).count();

    std::cout << "\n========== Replay Finished ==========\n";

std::cout << "Total Messages     : "
          << statistics.totalMessages
          << '\n';

std::cout << "System Events      : "
          << statistics.systemEvents
          << '\n';

std::cout << "Stock Directory    : "
          << statistics.stockDirectory
          << '\n';

std::cout << "Add Orders         : "
          << statistics.addOrders
          << '\n';

std::cout << "Execute Orders     : "
          << statistics.executeOrders
          << '\n';

std::cout
    << "Cancel Orders    : "
    << statistics.cancelOrders
    << '\n';

std::cout
    << "Active Orders     : "
    << orderBook.get_total_active_orders()
    << '\n';

std::cout << "Unknown Messages   : "
          << statistics.unknownMessages
          << '\n';


std::cout
    << "Elapsed Time      : "
    << seconds
    << " sec\n";

std::cout
    << "Throughput        : "
    << static_cast<uint64_t>(statistics.totalMessages / seconds)
    << " msg/sec\n";

}
