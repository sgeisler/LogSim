#ifndef CLOCKGATE_H
#define CLOCKGATE_H

#include "Gate.h"
#include "SFML/System.hpp"

class ClockGate : public Gate
{
    public:
        /** Default constructor */
        ClockGate();
        /** Default destructor */
        virtual ~ClockGate();

        string getName();
        size_t getInputCount();

        bool getOutput(size_t);
        size_t getOutputCount();
    protected:
    private:
        sf::Clock clock;
};

#endif // CLOCKGATE_H
