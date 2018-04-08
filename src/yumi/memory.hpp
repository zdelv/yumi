#include "../types.hpp"
#include <memory>
#include <vector>

class Memory
{

public:
    //TODO - Maybe make a class/struct for returned data
    //Gets the data at the given address
    //@input: uint32_t address
    //@output: uint8_t data
    u8 get_memory(u32 address);

    //Sets the data at the given address
    //@input: uint32_t address, uint8_t data
    //@output: none
    void set_memory(u32 address, u8 data);

    Memory();

    ~Memory();

private:
    std::vector<u8> memory_map;
};
