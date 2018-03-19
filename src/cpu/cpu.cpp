#include "cpu.h"

struct cpu regs; //Initialize CPU registers with struct cpu

void intial_regs()
{
    regs.sp_r13_regs[0] = 0x03007F00; //System & User SP init
    regs.sp_r13_regs[2] = 0x03007FE0; //Supervisor SP init
    regs.sp_r13_regs[4] = 0x03007FA0; //IRQ SP init
}

void operation_mode(uint32_t cpsr)
{
    uint32_t mode_bits;
    mode_bits = extract_last_bits(cpsr, mode_bits, 4);
    switch(mode_bits) {
        //TODO -- Add cases for different modes
    };
}