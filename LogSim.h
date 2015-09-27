#ifndef LOGSIM_H
#define LOGSIM_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include <LogSim.h>
#include <Gate.h>
#include <math.h>
#include <Logger.h>
#include <map>
#include <Pin.h>

#include <AndGate.h>

class LogSim
{
    public:
        LogSim();
        int run();
        ~LogSim();
    protected:
    private:
        sf::RenderWindow* window;

        sf::Vector2i mouseLastPos;
        sf::View menue;
        sf::View simulation;

        sf::Font font;

};

#endif // LOGSIM_H
