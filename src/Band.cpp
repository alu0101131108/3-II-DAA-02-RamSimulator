#include "../lib/Band.hpp"

Band::Band(const int &size) : cells_(size, 0), headPointer_(0)
{}

void Band::read(int &value)
{}

void Band::write(const int &value)
{}

void Band::loadFromFile(const std::string &filename)
{}

void Band::saveToFile(const std::string &filename)
{}