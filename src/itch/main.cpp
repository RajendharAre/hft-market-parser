#include "../../include/replay_engine.h"

#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    if(argc < 2 || argc > 3)
    {
        std::cout
            << "Usage:\n"
            << "  ./itch_reader <dataset_path> [max_messages]\n";

        return 1;
    }

    ReplayEngine engine;

    if(!engine.initialize(argv[1]))
    {
        std::cout << "Unable to open dataset.\n";
        return 1;
    }

    uint64_t limit = 0;

    if(argc == 3)
        limit = std::strtoull(argv[2], nullptr, 10);

    engine.replay(limit);

    return 0;
}
