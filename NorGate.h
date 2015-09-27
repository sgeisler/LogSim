#ifndef NORGATE_H
#define NORGATE_H

#include "Gate.h"


class NorGate : public Gate
{
    public:
        /** Default constructor */
        NorGate();
        /** Default destructor */
        virtual ~NorGate();

        string getName();
        size_t getInputCount();

        bool getOutput(size_t);
        size_t getOutputCount();
    protected:
    private:
};

#endif // NORGATE_H
