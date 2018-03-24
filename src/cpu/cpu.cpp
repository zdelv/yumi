#include <iostream>
#include "cpu.h"

/*
void cpu::initial_regs()
{
    cpu::regs.sp_r13_regs[0] = 0x03007F00; //System & User SP init
    cpu::regs.sp_r13_regs[2] = 0x03007FE0; //Supervisor SP init
    cpu::regs.sp_r13_regs[4] = 0x03007FA0; //IRQ SP init
}
*/
void cpu::current_op_mode(uint32_t cpsr, om& output_mode)
{
    uint32_t mode_bits;
    mode_bits = extract_last_bits(cpsr, mode_bits, 5);

    switch(mode_bits) {
        case 0b10000: 
            output_mode = user;
            break;
        case 0b10001: 
            output_mode = fiq;
            break;
        case 0b10010:
            output_mode = irq;
            break;
        case 0b10011: 
            output_mode = super;
            break;
        case 0b10111: 
            output_mode = abrt;
            break;
        case 0b11011: 
            output_mode = und;
            break;
        case 0b11111: 
            output_mode = sys;
            break;
        default:
            std::cout << "Invalid operation mode" << std::endl;
            break;
    }
}