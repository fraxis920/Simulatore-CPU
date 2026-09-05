#include "C:\Users\Francesco\OneDrive\Desktop\project\Cpu_emulator\include\ALU.h"

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


#include <iostream>
#include <bitset>
#include <stdexcept>
#include <iomanip>

// Funzione helper per stampare chiaramente il risultato e i flag
void printResult(const std::string& opName, const ALU::Result& res) {
    std::cout << std::left << std::setw(6) << opName << " -> "
              << "Bin: " << res.value << " (" 
              << std::right << std::setw(3) << res.value.to_ulong() << ") | "
              << "Flags [ Z: " << res.Zero 
              << " | C: " << res.Carry 
              << " | N: " << res.Negative 
              << " | V: " << res.Overflow << " ]\n";
}

int main() {
    ALU alu;

    // Input di prova
    std::bitset<8> A("10001101"); // 13 in decimale
    std::bitset<8> B("11000101"); // 5 in decimale

    std::cout << "Input A: " << A << " (" << A.to_ulong() << ")\n";
    std::cout << "Input B: " << B << " (" << B.to_ulong() << ")\n";
    std::cout << "---------------------------------------------------------\n";

    // 1. ADD (Addizione)
    printResult("ADD", alu.execute(ALU::Operation::ADD, A, B));

    // 2. SUB (Sottrazione)
    printResult("SUB", alu.execute(ALU::Operation::SUB, A, B));

    // 3. INC (Incremento A + 1)
    printResult("INC", alu.execute(ALU::Operation::INC, A));

    // 4. DEC (Decremento A - 1)
    printResult("DEC", alu.execute(ALU::Operation::DEC, A));

    // 5. AND (Logico Bitwise)
    printResult("AND", alu.execute(ALU::Operation::AND, A, B));

    // 6. OR (Logico Bitwise)
    printResult("OR",  alu.execute(ALU::Operation::OR, A, B));

    // 7. XOR (Logico Bitwise)
    printResult("XOR", alu.execute(ALU::Operation::XOR, A, B));

    // 8. NOT (Inversione Bitwise di A)
    printResult("NOT", alu.execute(ALU::Operation::NOT, A));

    // 9. SHL (Shift a Sinistra di B posizioni)
    printResult("SHL", alu.execute(ALU::Operation::SHL, A, std::bitset<8>(2))); // Shift di 2

    // 10. SHR (Shift a Destra di B posizioni)
    printResult("SHR", alu.execute(ALU::Operation::SHR, A, std::bitset<8>(2))); // Shift di 2

    return 0;
}




