#pragma once

#include <bitset>

class Buss
{
    private:
        std::bitset<16> address;
        std::bitset<8> data;

    public:
        Buss();

        void SetAddress(const std::bitset<16>& Address);
        std::bitset<16> GetAddress();

       void SetData(const std::bitset<8>& Data);
       std::bitset<8> GetData();
};