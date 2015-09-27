#ifndef XORGATE_H
#define XORGATE_H

#include "Gate.h"


class XorGate : public Gate
{
    public:
        /** Default constructor */
        XorGate();
        /** Default destructor */
        virtual ~XorGate();

        string getName();
        size_t getInputCount();

        bool getOutput(size_t);
        size_t getOutputCount();
    protected:
    private:
};

#endif // XORGATE_H
