#include "Logger.h"

void Logger::log(std::string msg)
{
    log(msg, 0);
}


void Logger::log(std::string msg, int level)
{
    if(LOG_LEVEL <= level)
    {
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        std::cout << "["
             << (now->tm_year + 1900) << '-'
             << (now->tm_mon + 1) << '-'
             <<  now->tm_mday << "; "
             <<  now->tm_hour << ":"
             <<  now->tm_min << ":"
             <<  now->tm_sec << "] "
             <<  msg
             << std::endl;
    }
}
