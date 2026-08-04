#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <cstdint>

class ITCHReader
{
public:

    bool open(const std::string& filename);

    bool next();

    const std::vector<char>& data() const;

    uint16_t length() const;

private:

    std::ifstream file;

    std::vector<char> buffer;

    uint16_t messageLength = 0;
};
