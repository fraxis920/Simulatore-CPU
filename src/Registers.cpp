#include "Registers.h"

Register::Register()    // Inizializzazione costruttore responsabile per lo start up della cpu
{
    
    A.reset();
    B.reset();
    C.reset();
    D.reset();

    PC.reset();
    SP.reset();

    IR.reset();

    FLAGS.reset();

}