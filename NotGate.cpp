#include "NotGate.h"

NotGate::NotGate()
{
    //ctor
}

NotGate::~NotGate()
{
    //dtor
}

string NotGate::getName()
{
    return "NOT";
}

size_t NotGate::getInputCount()
{
    return 1;
}

bool NotGate::getOutput(size_t pin)
{
    switch(pin)
    {
    case 0:
        return !inputs[0];
        break;
    default:
        return false;
    }
}

size_t NotGate::getOutputCount()
{
    return 1;
}
