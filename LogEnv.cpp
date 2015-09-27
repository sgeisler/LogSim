/*
 * LogEnv.cpp
 *
 *  Created on: 05.02.2015
 *      Author: sebastian
 */

#include "LogEnv.h"

LogEnv::LogEnv() {

}

LogEnv::~LogEnv() {
	// TODO Auto-generated destructor stub
}

void LogEnv::step()
{
	for(vector<Gate*>::iterator gate = gates.begin(); gate != gates.end(); ++gate)
	{
	    for(size_t input = 0; input < (*gate)->getInputCount(); input += 1)
        {
            //Wenn eine Verbindung besteht, Zustand weiterleiten
            if((*gate)->connections[input].gate != NULL)
            {
                (*gate)->setInput(input, (*gate)->connections[input].gate->getOutput((*gate)->connections[input].inputNumber));
            }
        }
	}
}

