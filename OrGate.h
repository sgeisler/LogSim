#ifndef ORGATE_H
#define ORGATE_H

#include "Gate.h"


class OrGate : public Gate
{
    public:
        /** Default constructor */
        OrGate();
        /** Default destructor */
        virtual ~OrGate();

        string getName();
        size_t getInputCount();

        bool getOutput(size_t);
        size_t getOutputCount();
    protected:
    private:
};

#endif // ORGATE_H
