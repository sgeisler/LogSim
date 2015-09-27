#include "AndGate.h"

AndGate::AndGate()
{
    //ctor
}

AndGate::~AndGate()
{
    //dtor
}

string AndGate::getName()
{
    return "AND";
}

size_t AndGate::getInputCount()
{
    return 2;
}

bool AndGate::getOutput(size_t pin)
{
    switch(pin)
    {
    case 0:
        return inputs[0] && inputs[1];
        break;
    default:
        return false;
    }
}

size_t AndGate::getOutputCount()
{
    return 1;
}
