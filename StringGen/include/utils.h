#pragma once

#include <string>

#include <fmt/printf.h>
#include <fmt/chrono.h>

class t_exec \
{
public:      
    t_exec(std::string str):m_str(str)
    {
          m_start = std::chrono::high_resolution_clock::now(); 
    }

    ~t_exec()
    {
          auto end = std::chrono::high_resolution_clock::now(); 
          std::chrono::duration<double> diff = end - m_start;
          fmt::printf(fmt::format(m_str.c_str(),diff.count()));

    }

private:    
    std::chrono::_V2::system_clock::time_point m_start;
    std::string m_str;
};