#include "..\include\Bus.h"

Buss::Buss()
{
    address.reset();
    data.reset();
}

void Buss::SetAddress(const std::bitset<16>& Address)
{
    address = Address;
}

std::bitset<16> Buss::GetAddress()
{
     return address;
}

void Buss::SetData(const std::bitset<8>& Data)
{
     data = Data;
}

std::bitset<8> Buss::GetData()
{
     return data;
}