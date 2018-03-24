#include <fstream>
#include <vector>
#include "cpu/cpu.h"
#include "log.h"


void game_title(char *title)
{
    std::cout << title << std::endl;
}

void open_file(char *path)
{
    std::ifstream file(path, std::ios::binary);
    std::vector<char> file_buf((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    for (int i = 0; i < 500; i++)
    {
        std::cout << file_buf[i];
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    Log::Level log_level = Log::Level::debug;
    const char error[] = "This is an error"; 
    game_title(argv[1]);
    std::vector<char> file_buf;
    //open_file(argv[1]);
    std::cout << "Hello World" << std::endl;
    Log::LogMessage(log_level, error);
    return 0;
    }
