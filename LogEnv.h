/*
 * LogEnv.h
 *
 *  Created on: 05.02.2015
 *      Author: sebastian
 */

#ifndef LOGENV_H_
#define LOGENV_H_

#include "Gate.h"
#include <string>
#include <vector>

using namespace std;


//Hier findet die Simulation statt
class LogEnv {
public:
	LogEnv();
	virtual ~LogEnv();

    //f�hrt einen Simulationsschritt aus
	void step();

    void load(std::string file);

    void save(std::string file);

protected:

    //beinhaltet die Pointer auf alle Gatter
	vector<Gate*> gates;
};

#endif /* LOGENV_H_ */
