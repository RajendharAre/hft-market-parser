cmake_minimum_required(VERSION 3.16)

project(HFTMarketParser)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(itch_reader
    src/itch/main.cpp
    src/itch/itch_reader.cpp
    src/itch/itch_decoder.cpp
    src/itch/replay_engine.cpp
)
