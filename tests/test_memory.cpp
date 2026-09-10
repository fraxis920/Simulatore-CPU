#include "..\src\Memory.cpp"
#include <iostream>

int main()
{
    Memory memory;

    std::bitset<16> Address("0001001000110100");
    std::bitset<8> Value("10101000");

    memory.Write(Address, Value);
    std::bitset<8> data = memory.Read(Address);
    std::cout << "Data: " << data << std::endl;
}