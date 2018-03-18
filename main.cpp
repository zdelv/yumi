#include <iostream>
#include <fstream>

using namespace std;

int game_title(char* title) {
    cout << title;
}

void open_file(char* path){
    ifstream fileData;
    fileData.open(path);
    char data[100];
    for (int i=0; i < 101; i++) {
            fileData >> data[i];
            cout << data[i];
    }
}


int main(int argc, char* argv[]) {
    game_title(argv[1]);
    open_file(argv[1]);

    cout << "Hello World"
    return 0;
}
