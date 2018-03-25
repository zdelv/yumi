#include <fstream>
#include <vector>
#include "gba/cpu/cpu.h"
#include "log.h"
#include "gba/loader/load.h"

void game_title(char *title)
{
    std::cout << title << std::endl;
}

int main(int argc, char *argv[])
{
    Log::Level log_level = Log::Level::debug;
    const char error[] = "This is an error"; 
    game_title(argv[1]);
    std::vector<char> buf = Load::create_file_buffer(argv[1]);    
    for (int i = 0; i < 500; i++)
    {
        std::cout << buf[i];
    }
    std::cout << "Hello World" << std::endl;
    LOG(log_level, error);
    return 0;
}