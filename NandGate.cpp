#include "NandGate.h"

NandGate::NandGate()
{
    //ctor
}

NandGate::~NandGate()
{
    //dtor
}

string NandGate::getName()
{
    return "NAND";
}

size_t NandGate::getInputCount()
{
    return 2;
}

bool NandGate::getOutput(size_t pin)
{
    switch(pin)
    {
    case 0:
        return !(inputs[0] && inputs[1]);
        break;
    default:
        return false;
    }
}

size_t NandGate::getOutputCount()
{
    return 1;
}
