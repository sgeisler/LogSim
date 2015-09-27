#include "XorGate.h"

XorGate::XorGate()
{
    //ctor
}

XorGate::~XorGate()
{
    //dtor
}

string XorGate::getName()
{
    return "XOR";
}

size_t XorGate::getInputCount()
{
    return 2;
}

bool XorGate::getOutput(size_t pin)
{
    switch(pin)
    {
    case 0:
        return inputs[0] ^ inputs[1];
        break;
    default:
        return false;
    }
}

size_t XorGate::getOutputCount()
{
    return 1;
}
