#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>
#include "include/utils.h"
#include "include/inc.h"

bool gen_data(size_t i);

bool gen_data(size_t i)
{
    std::unordered_map<std::string, std::string> m;
    std::vector<std::string> v;

    {
        t_exec a("\n\ntime to fill map:{}\n");
        while(m.size() != i)
        {
            std::string key(generate(50));
            m.insert(std::pair(key, generate(3000)));
            v.push_back(key);
        }
    }

    fmt::printf(fmt::format(FMT_STRING("size:{:d}\n"), m.size()));

    {
        t_exec b("time to search map:{}\n");
        for(const auto& s : v)
        {
            const auto p = m.find(s);
            if(p != m.end())
            {
                if(p->first.length() != 50)
                    fmt::printf(fmt::format(FMT_STRING("key:{:s}\n"), p->first));
            }
            else
            {
                
            }
        }
    }

    {
        t_exec c("time to copy map:{}\n");
        auto m1 = m;
    }
    return true; 
}

int main()
{

    const size_t y = 50000;
    t_exec z("Total Time :{}");
    for(int i  = 0;i < 10;i++)
        gen_data(y);

    auto i =  utf8_strlen("Hello world");   
    return 0;
} 
