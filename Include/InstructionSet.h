#pragma once

#include "Instruction.h"
#include <unordered_map>

class InstructionSet
{
    private:
        std::unordered_map<uint8_t, Instruction::Opcode> Decode = 
        {
        { 0x00, Instruction::Opcode::NOP },
        { 0x01, Instruction::Opcode::LOAD },
        { 0x02, Instruction::Opcode::STORE },
        { 0x03, Instruction::Opcode::MOV },
        { 0x04, Instruction::Opcode::ADD },
        { 0x05, Instruction::Opcode::SUB },
        { 0x06, Instruction::Opcode::INC },
        { 0x07, Instruction::Opcode::DEC },
        { 0x08, Instruction::Opcode::AND },
        { 0x09, Instruction::Opcode::OR },
        { 0x10, Instruction::Opcode::XOR },
        { 0x11, Instruction::Opcode::NOT },
        { 0x12, Instruction::Opcode::SHL },
        { 0x13, Instruction::Opcode::SHR },
        { 0x14, Instruction::Opcode::JMP },
        { 0x15, Instruction::Opcode::JZ },
        { 0x16, Instruction::Opcode::JNZ },
        { 0x17, Instruction::Opcode::HLT }
        };

    public:
        bool isValid(uint8_t Value) const;
        Instruction :: Opcode getDecode(uint8_t Value) const;

};