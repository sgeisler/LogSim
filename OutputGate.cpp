#include "OutputGate.h"

OutputGate::OutputGate()
{
    //ctor
}

OutputGate::~OutputGate()
{
    //dtor
}

string OutputGate::getName()
{
    if(inputs[0])
    {
        return "Out: 1";
    }
    else
    {
        return "Out: 0";
    }
}

size_t OutputGate::getInputCount()
{
    return 1;
}

bool OutputGate::getOutput(size_t)
{
    return false;
}

size_t OutputGate::getOutputCount()
{
 return 0;
}
