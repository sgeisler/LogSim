#include "Port.h"

Port::Port(Gate* parent, std::string name)
{
    this->parent = parent;
    this->name = name;
}

Port::~Port()
{
    //dtor
}
