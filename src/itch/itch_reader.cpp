#include "../../include/itch_reader.h"

bool ITCHReader::open(const std::string& filename)
{
    file.open(filename, std::ios::binary);

    return file.is_open();
}

bool ITCHReader::next()
{
    unsigned char bytes[2];

    if(!file.read(reinterpret_cast<char*>(bytes),2))
        return false;

    messageLength =
        (static_cast<uint16_t>(bytes[0])<<8) |
         static_cast<uint16_t>(bytes[1]);

    buffer.resize(messageLength);

    if(!file.read(buffer.data(),messageLength))
        return false;

    return true;
}

const std::vector<char>& ITCHReader::data() const
{
    return buffer;
}

uint16_t ITCHReader::length() const
{
    return messageLength;
}
