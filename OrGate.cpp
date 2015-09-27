#include "OrGate.h"

OrGate::OrGate()
{
    //ctor
}

OrGate::~OrGate()
{
    //dtor
}

string OrGate::getName()
{
    return "OR";
}

size_t OrGate::getInputCount()
{
    return 2;
}

bool OrGate::getOutput(size_t pin)
{
    switch(pin)
    {
    case 0:
        return inputs[0] || inputs[1];
        break;
    default:
        return false;
    }
}

size_t OrGate::getOutputCount()
{
    return 1;
}
