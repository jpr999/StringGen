#include <algorithm>
#include <chrono>
#include <experimental/source_location>
#include <iostream>
#include <list>
#include <random>
#include <string>

#include <fmt/printf.h>
#include "include/inc.h"

std::string generate(size_t max_length);

int main()
{
    std::vector<std::string> v;

    while(v.size() != 500)
    {
        for(int i = 0; i < 20; i++)
            generate(120);
        v.push_back(generate(120));
    }

    for(auto& str : v)
    {
        fmt::printf(fmt::format(FMT_STRING("{:s}\n"), str));
    }
    std::cout << std::endl;

    return 0;
}
