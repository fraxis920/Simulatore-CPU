#pragma once  //include once

#include <bitset>

class Register
{
    public:

        // Registri
        std::bitset<8> A = 0;
        std::bitset<8> B = 0;
        std::bitset<8> C = 0;
        std::bitset<8> D = 0;

        // Program counter
        std::bitset<16> PC;

        // Stack pointer
        std::bitset<16> SP;

        // Instruction register
        std::bitset<8> IR;

        // Flags
        std::bitset<8> FLAGS;
};