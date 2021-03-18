#include <algorithm>
#include <chrono>
#include <experimental/source_location>
#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <string>

#include <fmt/printf.h>
#include "include/inc.h"

std::string generate(size_t max_length);

int main()
{
    std::map<std::string,std::string> m;
    std::vector<std::string> v;

    while(m.size() != 2000)
    {
        std::string key(generate(50));
        m.insert(std::pair(key,generate(3000)));
        v.push_back(key);

    }

    for(auto& x : m)
    {
        fmt::printf(fmt::format(FMT_STRING("key:{:s}\n"),x.first));
    }
    std::cout << std::endl;
    fmt::printf(fmt::format(FMT_STRING("size:{:d}\n"),m.size()));

    for(const auto& s : v)
    {
        const auto p = m.find(s);
        if(p != m.end());
        {
            fmt::printf(fmt::format(FMT_STRING("key:{:s}\n"),p->first));

        }

    }

    return 0;
}
