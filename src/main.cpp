#include <fstream>
#include <vector>
#include "log.h"
#include "gba/gba.h"

void game_title(char *title)
{
    std::cout << title << std::endl;
}

int main(int argc, char *argv[])
{
    game_title(argv[1]);
    
    std::vector<char> output(500);

    std::cout << "Hello World" << std::endl;
    GBA::Loader loadertest;
    loadertest.create_file_buffer(argv[1]);    
    loadertest.read_buffer(500, 0, output);    
    return 0;
}