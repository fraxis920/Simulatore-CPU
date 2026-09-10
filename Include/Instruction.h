#pragma once

#include<cstdint>


class Instruction
{
public:

    enum class Opcode
    {
        //Controllo del sistema
        NOP   = 0x00, // No Operation: non esegue alcuna azione
        HLT   = 0x17, // ferma l'esecuzione del programma e della CPU

        //Gestione della Memoria e dei Registri
        LOAD  = 0x01, // Carica un valore dalla memoria principale all'interno di un registro della CPU
        STORE = 0x02, // Salva un valore da un registro della CPU all'interno della memoria principale
        MOV   = 0x03, // copia un valore da un registro a un altro

        //Operazioni Aritmetiche
        ADD   = 0x04, // Somma
        SUB   = 0x05, // Sottrae
        INC   = 0x06, // Incrementa
        DEC   = 0x07, // Decrementa

        //Operazioni Logiche Bitwisebit a bit
        AND   = 0x08, 
        OR    = 0x09, 
        XOR   = 0x10, 
        NOT   = 0x11, 

        //Operazioni di Scorrimento 
        SHL   = 0x12, // sposta i bit a sinistra 
        SHR   = 0x13, // sposta i bit a destra

        // Salti e Controllo del Flusso
        JMP   = 0x14, // salto incondizionato all'indirizzo specificato
        JZ    = 0x15, // salta all'indirizzo specificato SOLO se l'ultimo risultato è zero
        JNZ   = 0x16  // salta all'indirizzo specificato SOLO se l'ultimo risultato NON è zero.
    };

private:
    Opcode opcode;        //byte 1
    uint8_t operand1;    //byte 2
    uint8_t operand2;    //byte 3


public:
    Instruction(Opcode opcode, uint8_t Operand1, uint8_t Operand2);

    Opcode getOpcode() const;

    uint8_t getOperand1() const;
    uint8_t getOperand2() const;
};