#ifndef NANDGATE_H
#define NANDGATE_H

#include "Gate.h"


class NandGate : public Gate
{
    public:
        /** Default constructor */
        NandGate();
        /** Default destructor */
        virtual ~NandGate();

        string getName();
        size_t getInputCount();

        bool getOutput(size_t);
        size_t getOutputCount();
    protected:
    private:
};

#endif // NANDGATE_H
