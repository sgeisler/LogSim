#ifndef ANDGATE_H
#define ANDGATE_H

#include "Gate.h"

class AndGate : public Gate
{
    public:
        AndGate();
        virtual ~AndGate();

        string getName();
        size_t getInputCount();

        bool getOutput(size_t);
        size_t getOutputCount();
};

#endif // ANDGATE_H
