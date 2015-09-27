#include "Exception.h"
#include "Logger.h"

Exception::Exception(string msg)
{
    this->msg = msg;
};

void Exception::debug()
{
    Logger::log("\033[1m\033[91mException: \033[0m" + msg, 100);
};

string Exception::getMsg()
{
    return msg;
};
