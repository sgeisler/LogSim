#ifndef EXCEPTION_H
#define	EXCEPTION_H

#include <string>

using namespace std;

class Exception
{
private:
    string msg;
public:
    Exception(string msg);
    void debug();
    string getMsg();
};

#endif	/* EXCEPTION_H */

