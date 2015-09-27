#ifndef PORT_H
#define PORT_H

#include <SFML/System/Vector2.hpp>
#include <string>
#include "Gate.h"

class Port;
class Gate;

class Port
{
    public:
        Port(Gate* parent, std::string name);
        ~Port();

        void setState(bool update = true);
        bool getState();

        sf::Vector2f getPosition();

    protected:
    private:
        Gate* parent;
        std::string name;
};

#endif // PORT_H
