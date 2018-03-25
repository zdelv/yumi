#include <fstream>
#include <vector>

namespace Load {

    //Create a buffer vector for the file given
    //Input: Path to file
    //Output: Vector to buffer
    std::vector<char> create_file_buffer(char* path); 

}