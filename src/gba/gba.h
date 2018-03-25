#include "cpu/cpu.h"
#include "loader/load.h"

// Highest level namespace
// Manages most of the subclasses and provides a small interface to initialize the GBA
//
namespace GBA
{
    void run();       //TODO -- Generic run statement that means nothing
    void load_file(char *path); //TODO -- Generic load statement that means nothing

    class CPU;

    class GFX; //TODO -- Create GFX class (Graphics)

    class Loader;
}