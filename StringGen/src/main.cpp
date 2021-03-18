#include <algorithm>
#include <chrono>
#include <experimental/source_location>
#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <string>

#include <fmt/printf.h>
#include <fmt/chrono.h>

#include "include/inc.h"

std::string generate(size_t max_length);

int main()
{
    std::map<std::string,std::string> m;
    std::vector<std::string> v;

    auto start = std::chrono::high_resolution_clock::now();
    while(m.size() != 10000)
    {
        std::string key(generate(50));
        m.insert(std::pair(key,generate(3000)));
        v.push_back(key);

    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    fmt::print("time to fill map:{}\n",diff.count());
    
    
    fmt::printf(fmt::format(FMT_STRING("size:{:d}\n"),m.size()));

    auto start1 = std::chrono::high_resolution_clock::now();
    for(const auto& s : v)
    {
        const auto p = m.find(s);
        if(p != m.end());
        {
            if(p->first.length() != 50)            
                fmt::printf(fmt::format(FMT_STRING("key:{:s}\n"),p->first));

        }

    }

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1-start1;
    fmt::print("time to search map:{}\n",diff1.count());

    return 0;
}
