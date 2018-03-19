#include <iostream>
#include <fstream>
#include <vector>
#include "cpu/cpu.h"

using namespace std;

void game_title(char *title)
{
    cout << title << endl;
}

void open_file(char *path)
{
    ifstream file(path, ios::binary);
    vector<char> file_buf((istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    for (int i = 0; i < 500; i++)
    {
        cout << file_buf[i];
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    game_title(argv[1]);
    vector<char> file_buf;
    //open_file(argv[1]);
    uint32_t test = 0x2F;
    operation_mode mode = op_mode(test);
    cout << mode << endl;
    cout << "Hello World" << endl;
    return 0;
}
