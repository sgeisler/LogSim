/*
 * LogEnv.h
 *
 *  Created on: 05.02.2015
 *      Author: sebastian
 */

#ifndef LOGENV_H_
#define LOGENV_H_

#include "Gate.h"
#include <vector>

using namespace std;


//Hier findet die Simulation statt
class LogEnv {
public:
	LogEnv();
	virtual ~LogEnv();

    //führt einen Simulationsschritt aus
	void step();
protected:

    //beinhaltet die Pointer auf alle Gatter
	vector<Gate*> gates;
};

#endif /* LOGENV_H_ */
