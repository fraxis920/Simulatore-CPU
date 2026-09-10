#include "..\include\Instruction.h"

Instruction::Instruction(Opcode opcode, uint8_t operand1, uint8_t operand2) : opcode(opcode), operand1(operand1), operand2(operand2)
{
}

Instruction :: Opcode Instruction :: getOpcode() const
{
    return opcode;
}

uint8_t Instruction :: getOperand1() const
{
    return operand1;
}

uint8_t Instruction :: getOperand2() const
{
    return operand2;
}