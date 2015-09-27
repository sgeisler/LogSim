/*
 * Gate.h
 *
 *  Created on: 05.02.2015
 *      Author: sebastian
 */

#ifndef GATE_H_
#define GATE_H_

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <map>
#include <math.h>
#include <string>

using namespace std;

/*
* Gate ist eine abstrakte Klasse, von der alle Gatter-Arten abgeleitet werden
*/

class Gate {
public:

    //datentyp, welcher zum �bergeben eines bestimmten Pins verwendet wird
	struct Interface
	{
        Gate* gate;
		size_t inputNumber;

		enum Type
		{
            INPUT,
            OUTPUT
		};

		Type type;

		Interface()
		{
			gate = NULL;
		}
	};

	Gate();
	virtual ~Gate();

    //gibt die Darzustellende Bezeichnung des Gatters zur�ck
	virtual string getName() = 0;

    //liefert den Zustand eines Gattereingangs zur�ck
	virtual bool getInput(size_t);

	//setzt den Zustand eines Gattereingangs
	virtual void setInput(size_t, bool);

	//gibt zur�ck, wie viele Eing�nge ein Gatter besitzt
	virtual size_t getInputCount() = 0;

    //gibt den Zustand eines Ausgangs zur�ck
	virtual bool getOutput(size_t) = 0;

	//gibt die Anzahl an Ausg�ngen zur�ck
	virtual size_t getOutputCount() = 0;


    //Assoziatives Array, welches jedem Eingang einen Ausgang eines anderen Gates zuordnet.
    //Ist kein Eingang zugeordnet so wird Interface::gate auf NULL gesetzt
	std::map<size_t, Gate::Interface> connections;

	//Assoziatives Array, welches die Eingangszust�nde speichert
	std::map<size_t, bool> inputs;

	sf::Vector2f position; //top left corner

    //gibt an, ob ein Punkt auf dem Gatter Liegt
	virtual bool isInGate(sf::Vector2f);

	//gibt das unter dem Punkt liegende Interface zur�ck, wenn keines vorhanden ist wird Interface::gate auf NULL gesetzt
	virtual Interface getHoveredInterface(sf::Vector2f);

	//berechnet die H�he des Gatters (aus max. Pinzahl pro Seite)
	virtual float getHeight();

	//gibt den Mittelpunkt eines Pins des Interfaces zur�ck
	virtual sf::Vector2f getPinPosition(size_t pin, Interface::Type type);
};

#endif /* GATE_H_ */
