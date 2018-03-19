#include <stdint.h>
#include "../utils.cpp"

/* 
31 total registers, 32-bit.
Thumb only can access r0-r7, SP, LR, PC, CPSR and SPSR; ARM has full access
r0-r7, CPSR and SPSRs are identical between ARM and Thumb states
Thumb Stack Pointer (SP) maps onto ARM r13
Thumb Link Register (LR) maps onto ARM r14
Thumb Program Counter (PC) maps onto ARM PC r15
FIQ may be unused; IRQs are used instead
 */

struct cpu
{
    uint32_t gen_regs[13]; //r0-r12 -- Thumb uses only r0-r7
    uint32_t fiq_regs[5];  //r8-r12 -- FIQ banked registers -- ARM-state only

    uint32_t sp_r13_regs[6]; //Stack Pointer -- [0]Sys+User,[1]FIQ,[2]Supervisor,[3]Abort,[4]IRQ,[5]Undefined
    uint32_t lr_r14_regs[6]; //Link Register -- [0]Sys+User,[1]FIQ,[2]Supervisor,[3]Abort,[4]IRQ,[5]Undefined
    uint32_t pc_r15;         //Program Counter //TODO - Pipelining is 2 instr. ahead, probably important

    uint32_t cpsr;         //Current Program Status Register (Status Bits)
    uint32_t spsr_regs[5]; //Saved Program Status Register --  [0]FIQ,[1]Supervisor,[2]Abort,[3]IRQ,[4]Undefined
};

enum op_mode
{
    user,
    fiq,
    irq,
    super,
    abrt,
    und,
    sys
};

/*  Runs through the current operation mode on the CPSR
    Input: CPSR 
    Output: Nothing
 */
void current_operation_mode(uint32_t cpsr);

