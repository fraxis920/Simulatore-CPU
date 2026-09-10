#pragma once

#include <array>
#include <bitset>

class Memory    //61kb
{
    private:
        static constexpr std:: size_t Memory_Size = 65535;
        std::array<std::bitset<8>, Memory_Size> memory; 

    public:
        Memory();

        std::bitset<8> Read(const std::bitset<16>& address) const;

        void Write(const std::bitset<16>& address, const std::bitset<8>& value);
        
};