#ifndef OUTPUTGATE_H
#define OUTPUTGATE_H

#include "Gate.h"


class OutputGate : public Gate
{
    public:
        /** Default constructor */
        OutputGate();
        /** Default destructor */
        virtual ~OutputGate();

        string getName();
        size_t getInputCount();

        bool getOutput(size_t);
        size_t getOutputCount();
    protected:
    private:
};

#endif // OUTPUTGATE_H
