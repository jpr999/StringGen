#include <iostream>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>
#include <random>
#include <string>
#include "../include/inc.h"

std::string generate(size_t max_length)
{
    std::string possible_characters("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 engine(static_cast<unsigned int>(seed));

    std::uniform_int_distribution<> dist(0, static_cast<unsigned int>(possible_characters.size() - 1));

    std::string ret;
    
    while(max_length != ret.length())
    {
        ret += possible_characters[dist(engine)];
    }
    return ret;
}

