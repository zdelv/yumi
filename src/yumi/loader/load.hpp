#include "../../types.hpp"
#include <fstream>
#include <vector>

// Loading files for later use
// Mostly just creates and reads from a private vector buffer
class Loader
{

public:
    // Create a buffer vector for the file given
    // Input: Path to file
    // Output: Nothing; file_buf is filled for read_buffer use
    void create_file_buffer(const char* path);

    // Read bytes number of bytes at location iterator_start in to output_array
    // from the file_buf Input: int n number of bytes, int iterator_start address
    // to start at, u8 output_array to write bytes to Output: Return nothing,
    // output into output_array template<class T, size_t N>
    void read_buffer(int bytes, u32 interator_start, std::vector<u8>& output);

private:
    // Vector Buffer to file
    // Made of 1 byte u8s
    std::vector<u8> file_buf;
};
