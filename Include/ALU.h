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
            bool riporto = false;
            
            for(size_t index = 0; index < A.size(); ++index)
            {
               result[index] = A[index] ^ B[index] ^ riporto;              // somma con riporto in ingresso
               riporto = (A[index] & B[index]) | (B[index] & riporto) | (A[index] & riporto); // nuovo riporto  // Xor Calcolo
            }

            return computeFlags(A[7], B[7], result, riporto);
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

       Result computeFlags(const bool A, const bool B = 0, const std::bitset<8>& result, const bool& Carry)
       {
            Result res;

            res.value = result;

            res.Zero = result.none();                         // zero
            res.Carry = Carry;                               // <8 bit
            res.Negarive = result[7];                       // negativo
            res.Overflow = (A == B) && (result[7] != A);   // Overflow

            return res;
       }
};