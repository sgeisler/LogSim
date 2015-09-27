#ifndef LOGGER_H
#define LOGGER_H

/*
** Define which logs should be written to screen
** (INT_MIN to INT_MAX)
*/

#define LOG_LEVEL 0

#include <ctime>
#include <string>
#include <iostream>

class Logger
{
    public:
        static void log(std::string);
        static void log(std::string, int);
    protected:
    private:
};

#endif // LOGGER_H
