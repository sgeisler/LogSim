#include "NorGate.h"

NorGate::NorGate()
{
    //ctor
}

NorGate::~NorGate()
{
    //dtor
}

string NorGate::getName()
{
    return "NOR";
}

size_t NorGate::getInputCount()
{
    return 2;
}

bool NorGate::getOutput(size_t pin)
{
    switch(pin)
    {
    case 0:
        return !(inputs[0] || inputs[1]);
        break;
    default:
        return false;
    }
}

size_t NorGate::getOutputCount()
{
    return 1;
}
