#ifndef NOTGATE_H
#define NOTGATE_H

#include "Gate.h"


class NotGate : public Gate
{
    public:
        /** Default constructor */
        NotGate();
        /** Default destructor */
        virtual ~NotGate();

        string getName();
        size_t getInputCount();

        bool getOutput(size_t);
        size_t getOutputCount();
    protected:
    private:
};

#endif // NOTGATE_H
