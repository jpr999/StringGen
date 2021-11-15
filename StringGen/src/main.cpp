#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>
#include "include/utils.h"
#include "include/inc.h"

#if 1

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

    size_t y = 50000;
    t_exec z("Total Time :{}");
    for(int i  = 0;i < 10;i++)
        gen_data(y);

    return 0;
} 
#else


#include <iostream>
 
using namespace std;
 
int utf8_strlen(const string& s);
 
int main(int argc, char *argv[])
{
    string hello = "hello world"; //length 11
    string portg = "ol\xc3\xa1 mundo";//olá mundo length 9
    string nihao = "\xe4\xbd\xa0\xe5\xa5\xbd\xe4\xb8\x96\xe7\x95\x8c"; //你好世界 length 4
 
    cout << "string: " << hello << " length:" << utf8_strlen(hello) << endl;
    cout << "string: " << portg << " length:" << utf8_strlen(portg) << endl;
    cout << "string: " << nihao << " length:" << utf8_strlen(nihao) << endl;
    return 0;
}
 
int utf8_strlen(const string& str)
{
    int c;
    int i;
    int ix;
    int q;

    for (q=0, i=0, ix=str.length(); i < ix; i++, q++)
    {
        c = (unsigned char) str[i];
        if(c>=0 && c<=127)
        {
            i+=0;
        }
        else if ((c & 0xE0) == 0xC0)
        {
            i+=1;
        }
        else if ((c & 0xF0) == 0xE0)
        {
            i+=2;
        }
        else if ((c & 0xF8) == 0xF0)
        {
            i+=3;
        }
        else
        {
            return 0;//invalid utf8
        }
    }
    return q;
}

#endif
