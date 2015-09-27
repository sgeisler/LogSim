#ifndef INPUTGATE_H
#define INPUTGATE_H

#include "Gate.h"


class InputGate : public Gate
{
    public:
        /** Default constructor */
        InputGate();
        /** Default destructor */
        virtual ~InputGate();

        string getName();
        size_t getInputCount();

        virtual bool getOutput(size_t);
        size_t getOutputCount();
};

#endif // INPUTGATE_H
