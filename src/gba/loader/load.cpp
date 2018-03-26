#include "../../log.h"
#include "load.h"

namespace GBA {

void Loader::create_file_buffer(char *path)
{
    std::ifstream file(path, std::ios::binary);
    file.unsetf(std::ios::skipws); //Removes skips on \n

    //std::streampos fileSize; TODO -- Use this
    Loader::file_buf.assign((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
}

//template<class T, size_t N
void Loader::read_buffer(int bytes, uint32_t iterator_start, std::vector<char> &output)
{
    if (Loader::file_buf.empty())
    {
        LOG(Log::Level::error, "File Buffer not initialized! Run create_file_buffer first!");
        return;
    }
    else
    {
        for (int i = 0; i < bytes; i++)
        {
            output.at(i) = Loader::file_buf.at(i + iterator_start);
        };
    }
}

} //namespace GBA