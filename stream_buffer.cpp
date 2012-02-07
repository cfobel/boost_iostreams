#include <cstdio>
#include <string>
#include <iostream>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/stream.hpp>

namespace io = boost::iostreams;

int main()
{
    FILE* pipe = popen("find . -type f", "r");
    
    io::stream_buffer<io::file_descriptor_source> fpstream(fileno(pipe));
    std::istream in(&fpstream);
    
    std::string line;
    while (in)
    {
        std::getline(in, line);
        std::cout << line << std::endl;
    }
    return 0;
}
