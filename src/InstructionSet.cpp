#include "..\include\InstructionSet.h"

bool InstructionSet :: isValid(uint8_t Value) const
{
    return (Decode.contains(Value));
}

Instruction :: Opcode InstructionSet :: getDecode(uint8_t Value) const
{
   return Decode.at(Value);
}