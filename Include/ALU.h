#pragma once

#include <bitset>
#include <stdexcept>
#include <string>
#include <cstdint>

class ALU
{
    public:

        enum class Operation 
        {
            ADD,
            SUB,
            INC,
            DEC,
            AND,
            OR,
            XOR,
            NOT,
            SHL,
            SHR
        };

        struct Result 
        {
            std::bitset<8> value;

            bool Zero;        
            bool Carry;      
            bool Negarive; 
            bool Overflow; 
        };
 
       Result execute(Operation operation, const std::bitset<8>& A, const std::bitset<8>& B = 0)
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
    
    private:
       
       Result ADD(const std::bitset<8>& A, const std::bitset<8>& B)
       {
            std::bitset<8> result; 

            for(uint8_t i = 0; i<A.size(); i++)
            {

            }
       }

       Result SUB(const std::bitset<8>& A, const std::bitset<8>& B)
       {
        
       }

       Result INC(const std::bitset<8>& A)
       {
        
       }

       Result DEC(const std::bitset<8>& A)
       {
        
       }

       Result AND(const std::bitset<8>& A, const std::bitset<8>& B)
       {
        
       }

       Result OR(const std::bitset<8>& A, const std::bitset<8>& B)
       {
        
       }

       Result XOR(const std::bitset<8>& A, const std::bitset<8>& B)
       {
        
       }

       Result NOT(const std::bitset<8>& A)
       {
        
       }

       Result SHL(const std::bitset<8>& A, const std::bitset<8>& B = 0)
       {
        
       }

       Result SHR(const std::bitset<8>& A, const std::bitset<8>& B = 0)
       {
        
       }
};