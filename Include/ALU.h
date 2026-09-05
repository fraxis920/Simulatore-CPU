#include <bitset>
#include <stdexcept>
#include <string>

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
        bool Negative; 
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
        }
    }

    Result ADD(const std::bitset<8>& A, const std::bitset<8>& B)
    {
        std::bitset<8> result; 
        bool riporto = false;
        
        for(size_t index = 0; index < A.size(); ++index)
        {
            result[index] = A[index] ^ B[index] ^ riporto;              
            riporto = (A[index] & B[index]) | (B[index] & riporto) | (A[index] & riporto); 
        }

        bool overflow = (A[7] == B[7]) && (result[7] != A[7]);

        return computeFlags(result, riporto, overflow);
    }

    Result SUB(const std::bitset<8>& A, const std::bitset<8>& B)
    {
        std::bitset<8> B_inv = ~B;
        std::bitset<8> result; 
        bool carry = true;
        
        for(size_t i = 0; i < 8; ++i)
        {
            bool sum = A[i] ^ B_inv[i] ^ carry;
            carry = (A[i] & B_inv[i]) | (A[i] & carry) | (B_inv[i] & carry);
            result[i] = sum;
        }

        bool borrow = !carry;
        bool overflow = (A[7] != B[7]) && (result[7] != A[7]);

        return computeFlags(result, borrow, overflow);
    }

    Result INC(const std::bitset<8>& A)
    {
        std::bitset<8> result; 
        bool riporto = true;

        for(size_t index = 0; index < A.size(); ++index)
        {
            result[index] = A[index] ^ riporto;              
            riporto = A[index] & riporto; 
        }

        bool overflow = (!A[7]) && result[7];

        return computeFlags(result, riporto, overflow);
    }

    Result DEC(const std::bitset<8>& A)
    {
        return SUB(A, std::bitset<8>(1));
    }

    Result AND(const std::bitset<8>& A, const std::bitset<8>& B)
    {
        std::bitset<8> result; 

        for(size_t index = 0; index < A.size(); ++index)
        {
            result[index] = A[index] & B[index];               
        }

        return computeFlags(result, false, false);
    }

    Result OR(const std::bitset<8>& A, const std::bitset<8>& B)
    {
        std::bitset<8> result; 

        for(size_t index = 0; index < A.size(); ++index)
        {
            result[index] = A[index] | B[index];               
        }

        return computeFlags(result, false, false);
    }

    Result XOR(const std::bitset<8>& A, const std::bitset<8>& B)
    {
        std::bitset<8> result; 

        for(size_t index = 0; index < A.size(); ++index)
        {
            result[index] = A[index] ^ B[index];               
        }

        return computeFlags(result, false, false);
    }

    Result NOT(const std::bitset<8>& A)
    {
        std::bitset<8> result; 

        for(size_t index = 0; index < A.size(); ++index)
        {
            result[index] = !A[index];               
        }

        return computeFlags(result, false, false);
    }

    Result SHL(const std::bitset<8>& A, const std::bitset<8>& B = std::bitset<8>(0))
    {
        unsigned long shift_amount = B.to_ulong();
        std::bitset<8> result = A;
        bool carry_out = false;

        if (shift_amount > 0) 
        {
            if (shift_amount >= 8) 
            {
                carry_out = false; 
                result.reset();
            } 
            else 
            {
                carry_out = result[8 - shift_amount];
                result <<= shift_amount;
            }
        }

        return computeFlags(result, carry_out, false);
    }

    Result SHR(const std::bitset<8>& A, const std::bitset<8>& B = std::bitset<8>(0))
    {
        unsigned long shift_amount = B.to_ulong();
        std::bitset<8> result = A;
        bool carry_out = false;

        if (shift_amount > 0) 
        {
            if (shift_amount >= 8) 
            {
                carry_out = false;
                result.reset();
            } 
            else 
            {
                carry_out = result[shift_amount - 1];
                result >>= shift_amount;
            }
        }

        return computeFlags(result, carry_out, false);
    }

    Result computeFlags(const std::bitset<8>& result, const bool Carry, const bool Overflow)
    {
        Result res;

        res.value = result;
        res.Zero = result.none();
        res.Carry = Carry;
        res.Negative = result[7];
        res.Overflow = Overflow;

        return res;
    }
};