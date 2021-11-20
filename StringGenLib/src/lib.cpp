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

size_t utf8_strlen(const std::string& str)
{
    size_t c;
    size_t i;
    size_t ix;
    size_t q;

    for(q = 0, i = 0, ix = str.length(); i < ix; i++, q++)
    {
        c = (unsigned char)str[i];
        if(c >= 0 && c <= 127)
        {
            i += 0;
        }
        else if((c & 0xE0) == 0xC0)
        {
            i += 1;
        }
        else if((c & 0xF0) == 0xE0)
        {
            i += 2;
        }
        else if((c & 0xF8) == 0xF0)
        {
            i += 3;
        }
        else
        {
            return 0; //invalid utf8
        }
    }
    return q;
}
