#include "..\include\Memory.h"
#include <array>

Memory::Memory()
{
    for(auto& byte : memory)
    {
        byte.reset();
    }
}

std::bitset<8> Memory::Read(const std::bitset<16>& address) const
{
    return memory[address.to_ulong()];
}

void Memory::Write(const std::bitset<16>& address, const std::bitset<8>& value)
{
    memory[address.to_ulong()] = value;
}