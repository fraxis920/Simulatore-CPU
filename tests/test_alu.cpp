#include "..\src\ALU.cpp"

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

    std::bitset<8> A("10001101"); 
    std::bitset<8> B("11000101"); 

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
    printResult("SHL", alu.execute(ALU::Operation::SHL, A, std::bitset<8>(2))); 

    // 10. SHR (Shift a Destra di B posizioni)
    printResult("SHR", alu.execute(ALU::Operation::SHR, A, std::bitset<8>(2))); 

    return 0;
}