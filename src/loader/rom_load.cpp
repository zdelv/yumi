#include "load.h"

namespace Load {

   std::vector<char> create_file_buffer(char* path) 
   {
        std::ifstream file(path, std::ios::binary);
        file.unsetf(std::ios::skipws); //Removes skips on \n
        
        std::streampos fileSize;
        std::vector<char> file_buf((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
        return file_buf;
   }    

}