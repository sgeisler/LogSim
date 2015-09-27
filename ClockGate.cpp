#include "ClockGate.h"

ClockGate::ClockGate()
{
    clock.restart();
}

ClockGate::~ClockGate()
{
    //dtor
}

string ClockGate::getName()
{
    return "Clock";
}

size_t ClockGate::getInputCount()
{
    return 0;
}

bool ClockGate::getOutput(size_t pin)
{
    if(clock.getElapsedTime().asMilliseconds() >= 1000)
    {
        inputs[0] = !inputs[0];
        clock.restart();
    }

    switch(pin)
    {
    case 0:
        return inputs[0];
        break;
    default:
        return false;
    }
}

size_t ClockGate::getOutputCount()
{
    return 1;
}
