#include "cpu.h"

struct cpu regs; //Initialize CPU registers with struct cpu

void intial_regs()
{
    regs.sp_r13_regs[0] = 0x03007F00; //System & User SP init
    regs.sp_r13_regs[2] = 0x03007FE0; //Supervisor SP init
    regs.sp_r13_regs[4] = 0x03007FA0; //IRQ SP init
}

operation_mode op_mode(uint32_t cpsr)
{
    uint32_t mode_bits;
    operation_mode mode;
    mode_bits = extract_last_bits(cpsr, mode_bits, 5);
    switch(mode_bits) {
        case 0b10000 {
            mode = user;
        }
        case 0b10001 {
            mode = fiq;
        }
        case 0b10010 {
            mode = irq;
        }
        case 0b10011 {
            mode = super;
        }
        case 0b10111 {
            mode = abrt;
        }
        case 0b11011 {
            mode = und;
        }
        case 0b11111 {
            mode = sys;
        }
    };
    return mode;
}