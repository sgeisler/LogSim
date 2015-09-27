#include "Gate.h"

Gate::Gate()
{
    //ctor
}

Gate::~Gate()
{
    //dtor
}

bool Gate::getInput(size_t pin)
{
    return inputs[pin];
}

void Gate::setInput(size_t pin, bool state)
{
    inputs[pin] = state;
}

bool Gate::isInGate(sf::Vector2f point)
{
    if((point.x < position.x) ||
       (point.x > position.x + 100.0f))
    {
        return false;
    }
    if((point.y < position.y) ||
       (point.y > position.y + getHeight()))
    {
        return false;
    }
    return true;
}

float Gate::getHeight()
{
    return (25.0f + (float)(this->getOutputCount() > this->getInputCount() ? this->getOutputCount() : this->getInputCount()) * 25.0f);
}

Gate::Interface Gate::getHoveredInterface(sf::Vector2f point)
{
    Gate::Interface ret;
    sf::Vector2f dist;

    for(size_t pin = 0; pin < (this->getInputCount()); pin += 1)
    {
        dist = (getPinPosition(pin, Gate::Interface::INPUT) - point);
        if(pow(dist.x, 2) + pow(dist.y, 2) < 25)
        {
            ret.gate = this;
            ret.inputNumber = pin;
            ret.type = Gate::Interface::INPUT;

            return ret;
        }
    }

    for(size_t pin = 0; pin < (this->getOutputCount()); pin += 1)
    {
        dist = (getPinPosition(pin, Gate::Interface::OUTPUT) - point);
        if(pow(dist.x, 2) + pow(dist.y, 2) < 25)
        {
            ret.gate = this;
            ret.inputNumber = pin;
            ret.type = Gate::Interface::OUTPUT;

            return ret;
        }
    }

    ret.gate = NULL;
    return ret;
}

sf::Vector2f Gate::getPinPosition(size_t pin, Interface::Type type)
{
    if(type == Gate::Interface::INPUT)
    {
        return this->position + sf::Vector2f(5.0f, 25.0f) + sf::Vector2f(0.0f, 25.0f * pin);
    }
    else
    {
        return this->position + sf::Vector2f(95.0f, 25.0f) + sf::Vector2f(0.0f, 25.0f * pin);
    }
}
