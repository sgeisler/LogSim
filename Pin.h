#ifndef PIN_H_INCLUDED
#define PIN_H_INCLUDED

struct Pin
{
    size_t gate;
    size_t pin;

    Pin(size_t gate, size_t pin)
    {
        this->gate = gate;
        this->pin = pin;
    }
};

#endif // PIN_H_INCLUDED
