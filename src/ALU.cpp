#include "..\include\ALU.h"
#include <iostream>
#include <bitset>
#include <stdexcept>
#include <iomanip>

ALU::Result ALU::execute(Operation operation, const std::bitset<8>& A, const std::bitset<8>& B)
{
    
    switch (operation)
            {
            case Operation::ADD: 
                return ADD(A, B); 
                
            case Operation::SUB: 
                return SUB(A, B);

            case Operation::INC: 
                return INC(A);

            case Operation::DEC: 
                return DEC(A);

            case Operation::AND: 
                return AND(A, B);

            case Operation::OR: 
                return OR(A, B);

            case Operation::XOR:   
                return XOR(A, B);

            case Operation::NOT: 
                return NOT(A);

            case Operation::SHL: 
                return SHL(A, B);

            case Operation::SHR: 
                return SHR(A, B);
            
            default:
                throw std::invalid_argument("Errore: Operation non valida: " + std::to_string(static_cast<int>(operation)));
                break;
            }
            
}




