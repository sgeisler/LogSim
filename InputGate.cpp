#include "InputGate.h"

InputGate::InputGate()
{
    //ctor
}

InputGate::~InputGate()
{
    //dtor
}

string InputGate::getName()
{
    if(inputs[0])
    {
        return "Inp: 1";
    }
    else
    {
        return "Inp: 0";
    }

}

size_t InputGate::getInputCount()
{
    return 0;
}

bool InputGate::getOutput(size_t pin)
{
    switch(pin)
    {
    case 0:
        return inputs[0];
        break;
    default:
        return false;
    }
}

size_t InputGate::getOutputCount()
{
    return 1;
}
