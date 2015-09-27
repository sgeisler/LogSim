/*
 * LogWindow.h
 *
 *  Created on: 05.02.2015
 *      Author: sebastian
 */

#ifndef LOGWINDOW_H_
#define LOGWINDOW_H_

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "LogEnv.h"
#include <iostream>

#include "AndGate.h"
#include "InputGate.h"
#include "OutputGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "NandGate.h"
#include "NorGate.h"
#include "XorGate.h"
#include "ClockGate.h"

class LogWindow : LogEnv
{
public:
	LogWindow();
	virtual ~LogWindow();

    //wird zu Beginn aufgerufen, l�uft bis das Fenster geschlossen wird
    //hier wird die Eventverarbeitung und das Rendering durchgef�hrt
	void run();
private:
    //Fenster, in das gezeichnet wird
	sf::RenderWindow wnd;

	//letzte Mausposition, um delta zu errechnen
    sf::Vector2i mouseLastPos;


    //Pointer auf das Gatter, welches gerade verschoben wird
    Gate* dragged;

    //Ein Interface, zu dem gerade eine Verbindung erstellt wird
    //Wenn ungenutzt ist Interface::gate == NULL
    Gate::Interface connect;

    //gibt an, ob Verbindungen gewinkelt oder direkt gezeichnet werden
    bool wireStyle;

    //gibt an, ob gerade ein Gatter hinzugef�gt wird (wenn ja, dann >=0)
    //und welches typs es ist.
    int addGateType;

    std::string inputString = "";
    int action = 0;


    //Rotations-/Transformationsmatritzen f�r Men� und Zeichenfl�che
    sf::View menue;
    sf::View simulation;

    //Schriftart zum darstellen von Text
    sf::Font font;

    //Zeichnet alle Gatter und Verbindungen
	void renderComponents();

	//zeichnet ein Gatter
	void drawGate(Gate*);

	//zeichnet eine Verbindung
	void drawConnection(sf::Vector2f from, sf::Vector2f to);

    //liefert einen Zeiger auf das Gatter unter dem Mauszeiger zur�ck
	Gate* getFocusedGate();
};

#endif /* LOGWINDOW_H_ */
