/*
 * LogEnv.cpp
 *
 *  Created on: 05.02.2015
 *      Author: sebastian
 */

#include <fstream>
#include "LogEnv.h"
#include "json/src/json.hpp"

#include "AndGate.h"
#include "ClockGate.h"
#include "InputGate.h"
#include "NandGate.h"
#include "NorGate.h"
#include "NotGate.h"
#include "OrGate.h"
#include "OutputGate.h"
#include "XorGate.h"

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

void LogEnv::load(string file)
{
    for (vector<Gate *>::iterator it = gates.begin(); it != gates.end(); ++it)
    {
        delete (*it);
    }
    gates.clear();

    nlohmann::json in;

    ifstream inFile;
    inFile.open(file);

    if (!inFile.is_open())
    {
        return;
    }

    in << inFile;
    inFile.close();

    std::map<long, Gate *> gateIds;

    for (auto gate : in)
    {
        Gate *n;

        if (gate["type"] == "Inp: 0")
        {
            n = new InputGate();
            n->setInput(0, false);
        }
        if (gate["type"] == "Inp: 1")
        {
            n = new InputGate();
            n->setInput(0, true);
        }
        if (gate["type"] == "Out: 0")
        {
            n = new OutputGate();
        }
        if (gate["type"] == "Out: 1")
        {
            n = new OutputGate();
        }
        if (gate["type"] == "AND")
        {
            n = new AndGate();
        }
        if (gate["type"] == "OR")
        {
            n = new OrGate();
        }
        if (gate["type"] == "NOT")
        {
            n = new NotGate();
        }
        if (gate["type"] == "NAND")
        {
            n = new NandGate();
        }
        if (gate["type"] == "NOR")
        {
            n = new NorGate();
        }
        if (gate["type"] == "XOR")
        {
            n = new XorGate();
        }
        if (gate["type"] == "Clock")
        {
            n = new ClockGate();
        }

        n->position = sf::Vector2f(gate["pos_x"], gate["pos_y"]);
        gates.push_back(n);
        gateIds[gate["id"]] = n;
    }

    for (auto gate : in)
    {
        for (auto con : gate["con"])
        {
            Gate::Interface i;
            i.gate = gateIds[con["gate_from"]];
            i.type = Gate::Interface::OUTPUT;
            i.inputNumber = con["pin_from"];
            gateIds[gate["id"]]->connections[con["pin_to"]] = i;
        }
    }

    cout << "loading " << file << endl;
}

void LogEnv::save(string file)
{

    nlohmann::json out;

    for (vector<Gate *>::iterator it = gates.begin(); it != gates.end(); ++it)
    {
        nlohmann::json gate;
        for (size_t input = 0; input < (*it)->getInputCount(); input += 1)
        {
            nlohmann::json con;
            con["gate_from"] = (long) (*it)->connections[input].gate;
            con["pin_from"] = (*it)->connections[input].inputNumber;
            con["pin_to"] = input;
            gate["con"].push_back(con);
        }
        gate["id"] = (long) (*it);
        gate["pos_x"] = (*it)->position.x;
        gate["pos_y"] = (*it)->position.y;
        gate["type"] = (*it)->getName();

        out.push_back(gate);
    }

    ofstream outFile;
    outFile.open(file);
    outFile << out.dump(4);
    outFile.close();
}