/*
 * LogWindow.cpp
 *
 *  Created on: 05.02.2015
 *      Author: sebastian
 */

#include "LogWindow.h"


LogWindow::LogWindow() {
    if (!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf"))
    {
        std::cout << "Error loding font ..." << std::endl;
    }

	addGateType = -1;
	wireStyle = false;
	dragged = NULL;
}

LogWindow::~LogWindow() {
	// TODO Auto-generated destructor stub
}

void LogWindow::run()
{
    //initialisieren des Fensters
	wnd.create(sf::VideoMode(800, 600), "LogSim 0.1");
    wnd.display();
    wnd.setSize(sf::Vector2u(800, 600));
    wnd.setFramerateLimit(60);

    //views einrichten (Menuegroesse, Zeichenflaeche)
    menue.setSize(wnd.getSize().x, 130.0f);
    menue.setCenter(wnd.getSize().x / 2.0f, 65.0f);
    menue.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 130.0f / wnd.getSize().y));

    simulation.setSize(wnd.getSize().x, wnd.getSize().y - 130.0f);
    simulation.setViewport(sf::FloatRect(0.0f, 130.0f / wnd.getSize().y, 1.0f, 1.0f - (130.0f / wnd.getSize().y)));

    //Beginn der Endlosschleife, bis das Fenster geschlossen wird
    while (wnd.isOpen())
    {

        //Abfangen der Events
        sf::Event event;
        while (wnd.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                wnd.close();
            }

            if(event.type == sf::Event::Resized)
            {
                menue.setSize(event.size.width, 130.0f);
                menue.setCenter(event.size.width / 2.0f, 65.0f);
                menue.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 130.0f / event.size.height));

                simulation.setSize(event.size.width, event.size.height - 130.0f);
                simulation.setViewport(
                        sf::FloatRect(0.0f, 130.0f / event.size.height, 1.0f, 1.0f - (130.0f / event.size.height)));
            }

            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Right)
                {
                    mouseLastPos = sf::Mouse::getPosition(wnd);
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    Gate* focus = getFocusedGate();
                    if(focus != NULL)
                    {
                        Gate::Interface i = focus->getHoveredInterface(wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd)));
                        if(i.gate != NULL)
                        {
                            connect = i;
                        }
                        else
                        {
                            dragged = focus;
                        }
                    }
                }
            }

            if(event.type == sf::Event::MouseButtonReleased)
            {
                dragged = NULL;

                Gate* focus = getFocusedGate();
                if(focus != NULL)
                {
                    Gate::Interface i = focus->getHoveredInterface(wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd)));
                    if((i.gate != NULL) && (connect.gate != NULL) && (connect.type != i.type))
                    {
                        if(i.type == Gate::Interface::INPUT)
                        {
                            if(i.gate->connections[i.inputNumber].gate == NULL)
                            {
                                i.gate->connections[i.inputNumber] = connect;
                            }
                        }
                        else
                        {
                            if(connect.gate->connections[connect.inputNumber].gate == NULL)
                            {
                                connect.gate->connections[connect.inputNumber] = i;
                            }
                        }
                    }

                    if(event.mouseButton.button == sf::Mouse::Right)
                    {
                        if(focus->getName() == "Inp: 0")
                        {
                            focus->setInput(0, true);
                        }
                        else if(focus->getName() == "Inp: 1")
                        {
                            focus->setInput(0, false);
                        }
                    }
                }

                connect.gate = NULL;


            }

            if(event.type == sf::Event::MouseMoved)
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
                {
                    simulation.move(sf::Vector2f(wnd.mapPixelToCoords(mouseLastPos) - wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd))));
                }
                if((dragged != NULL))
                {
                    dragged->position = dragged->position - sf::Vector2f(wnd.mapPixelToCoords(mouseLastPos) - wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd)));
                }
                mouseLastPos = sf::Mouse::getPosition(wnd);
            }

            if(event.type == sf::Event::MouseWheelMoved)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    //�ndern des hinzuzuf�genden Gatters
                    if(event.mouseWheel.delta < 0)
                    {
                        addGateType -= 1;
                    }
                    else
                    {
                        addGateType += 1;
                    }

                    if(addGateType < 0)
                    {
                        addGateType = 8;
                    }

                    if(addGateType > 8)
                    {
                        addGateType = 0;
                    }

                    switch(addGateType)
                    {
                    case 0:
                        delete gates.back();
                        gates.back() = new InputGate();
                        dragged = (gates.back());
                        dragged->position = wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd));
                        break;
                    case 1:
                        delete gates.back();
                        gates.back() = new OutputGate();
                        dragged = (gates.back());
                        dragged->position = wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd));
                        break;
                    case 2:
                        delete gates.back();
                        gates.back() = new AndGate();
                        dragged = gates.back();
                        dragged->position = wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd));
                        break;
                    case 3:
                        delete gates.back();
                        gates.back() = new OrGate();
                        dragged = gates.back();
                        dragged->position = wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd));
                        break;
                    case 4:
                        delete gates.back();
                        gates.back() = new NotGate();
                        dragged = gates.back();
                        dragged->position = wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd));
                        break;
                    case 5:
                        delete gates.back();
                        gates.back() = new NandGate();
                        dragged = (gates.back());
                        dragged->position = wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd));
                        break;
                    case 6:
                        delete gates.back();
                        gates.back() = new NorGate();
                        dragged = (gates.back());
                        dragged->position = wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd));
                        break;
                    case 7:
                        delete gates.back();
                        gates.back() = new XorGate();
                        dragged = gates.back();
                        dragged->position = wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd));
                        break;
                    case 8:
                        delete gates.back();
                        gates.back() = new ClockGate();
                        dragged = gates.back();
                        dragged->position = wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd));
                        break;
                    }
                }
                else
                {
                    simulation.zoom(1.0f +((float)(event.mouseWheel.delta)) / 10.0f);
                }
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::A)
                {
                    //Hinzuf�gen eines Gatters
                    if(addGateType < 0)
                    {
                        dragged = new InputGate();
                        gates.push_back(dragged);
                        dragged->position = wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd));
                        addGateType = 0;
                    }
                }

                if(event.key.code == sf::Keyboard::W)
                {
                    //Linienstil �ndern
                    wireStyle = !wireStyle;
                }

                if(event.key.code == sf::Keyboard::D)
                {
                    Gate* focus = getFocusedGate();
                    if(focus != NULL)
                    {
                        //L�schen einzelner Verbindungen
                        Gate::Interface i = focus->getHoveredInterface(wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd)));
                        if(i.gate != NULL)
                        {
                            if(i.type == Gate::Interface::INPUT)
                            {
                                i.gate->connections[i.inputNumber].gate = NULL;
                            }
                            else
                            {
                                for(vector<Gate*>::iterator gate = gates.begin(); gate != gates.end(); ++gate)
                                {
                                    for(size_t input = 0; input < (*gate)->getInputCount(); input += 1)
                                    {
                                        if(((*gate)->connections[input].gate == i.gate) && ((*gate)->connections[input].inputNumber == i.inputNumber))
                                        {
                                            (*gate)->connections[input].gate = NULL;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            //L�schen eines Gatters (und Entfernen dessen Verbindungen)
                            vector<Gate*>::iterator del;
                            for(vector<Gate*>::iterator gate = gates.begin(); gate != gates.end(); ++gate)
                            {
                                for(size_t input = 0; input < (*gate)->getInputCount(); input += 1)
                                {
                                    if((*gate)->connections[input].gate == focus)
                                    {
                                        (*gate)->connections[input].gate = NULL;
                                    }
                                }
                                if((*gate) == focus)
                                {
                                    del = gate;
                                }
                            }
                            gates.erase(del);
                            delete focus;
                        }
                    }
                }
            }

            if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::A)
                {
                    if(addGateType >= 0)
                    {
                        dragged = NULL;
                        addGateType = -1;
                    }
                }

                if (action == 0)
                {
                    //open save dialog
                    if (event.key.code == sf::Keyboard::S)
                    {
                        action = 1;
                    }

                    //open load dialog
                    if (event.key.code == sf::Keyboard::L)
                    {
                        action = 2;
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                //close open dialog
                if (event.key.code == sf::Keyboard::Escape)
                {
                    action = 0;
                    inputString = "";
                }
            }

            if (event.type == sf::Event::TextEntered)
            {
                if (action != 0)
                {
                    if (static_cast<int>(event.text.unicode) == 13)
                    {
                        if (action == 1)
                        {
                            save(inputString);
                        }
                        else if (action == 2)
                        {
                            load(inputString);
                        }
                        inputString = "";
                        action = 0;
                    }
                    else if (static_cast<int>(event.text.unicode) != 8)
                    {
                        inputString += static_cast<char>(event.text.unicode);
                    }
                    else if (inputString.size() > 0)
                    {
                        inputString.pop_back();
                    }
                }
            }
        }
        this->step();
        this->renderComponents();
    }
}

void LogWindow::renderComponents()
{

    wnd.clear(sf::Color::White);

    //Men� Zeichnen
    wnd.setView(menue);

    sf::RectangleShape r(sf::Vector2f(menue.getSize().x, 100));
    r.setPosition(sf::Vector2f(0, 0));
    r.setFillColor(sf::Color::Blue);
    wnd.draw(r);
    wnd.draw(r);

    sf::Text desc("Press 'A' to add gates. \nBy scrolling while holding 'A' you can choose between different gate types.\n\nPress 'D' to delete gates or to remove all connections from/to an out-/input \n\nPress 'W' to change the routing of the connections.", font);
    desc.setPosition(sf::Vector2f(0.0f, 0.0f));
    desc.setCharacterSize(12);
    wnd.draw(desc);

    if (action == 1)
    {
        sf::Text cmd("Save as File: " + inputString, font);
        cmd.setPosition(sf::Vector2f(10.0f, 100.0f));
        cmd.setColor(sf::Color::Black);
        cmd.setCharacterSize(16);
        wnd.draw(cmd);
    }
    else if (action == 2)
    {
        sf::Text cmd("Load from File: " + inputString, font);
        cmd.setPosition(sf::Vector2f(10.0f, 100.0f));
        cmd.setColor(sf::Color::Black);
        cmd.setCharacterSize(16);
        wnd.draw(cmd);
    }

    //Gatter und Verbindungen zeichnen
    wnd.setView(simulation);

	for(vector<Gate*>::iterator gate = gates.begin(); gate != gates.end(); ++gate)
	{
        drawGate(*gate);

        for(size_t input = 0; input < (*gate)->getInputCount(); input += 1)
        {
            if((*gate)->connections[input].gate != NULL)
            {
                drawConnection((*gate)->getPinPosition(input, Gate::Interface::INPUT),
                               (*gate)->connections[input].gate->getPinPosition((*gate)->connections[input].inputNumber, Gate::Interface::OUTPUT));
            }
        }
	}

    //Verbindung eines Pins zum Mauzeiger zeichnen, w�hrend die Verbindung noch erstellt wird
    if(connect.gate != NULL)
    {
        drawConnection(connect.gate->getPinPosition(connect.inputNumber, connect.type), wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd)));
    }

    wnd.display();
}

Gate* LogWindow::getFocusedGate()
{
    for(vector<Gate*>::iterator gate = gates.begin(); gate != gates.end(); ++gate)
	{
        if((*gate)->isInGate(wnd.mapPixelToCoords(sf::Mouse::getPosition(wnd))))
        {
            return (*gate);
        }
	}
	return NULL;
}

void LogWindow::drawGate(Gate* g)
{
    sf::RectangleShape gateShape(sf::Vector2f(90.0f, g->getHeight() - 10.0f));
    gateShape.setPosition(g->position + sf::Vector2f(5.0f, 5.0f));
    gateShape.setFillColor(sf::Color::Black);
    wnd.draw(gateShape);

    sf::CircleShape pinShape(5.0f);

    for(size_t pin = 0; pin < (g->getInputCount()); pin += 1)
    {
        if(g->getInput(pin))
        {
            pinShape.setFillColor(sf::Color::Green);
        }
        else
        {
            pinShape.setFillColor(sf::Color::Red);
        }
        pinShape.setPosition(g->getPinPosition(pin, Gate::Interface::INPUT) - sf::Vector2f(5.0f, 5.0f));
        wnd.draw(pinShape);
    }

    for(size_t pin = 0; pin < (g->getOutputCount()); pin += 1)
    {
        if(g->getOutput(pin))
        {
            pinShape.setFillColor(sf::Color::Green);
        }
        else
        {
            pinShape.setFillColor(sf::Color::Red);
        }
        pinShape.setPosition(g->getPinPosition(pin, Gate::Interface::OUTPUT) - sf::Vector2f(5.0f, 5.0f));
        wnd.draw(pinShape);
    }

    sf::Text name(g->getName(), font);
    name.setPosition(g->position + sf::Vector2f(15.0f, g->getHeight() / 2.0f - 15.0f));
    name.setCharacterSize(20);
    wnd.draw(name);
}

void LogWindow::drawConnection(sf::Vector2f from, sf::Vector2f to)
{
    if(wireStyle)
    {
        sf::Vertex line[] =
        {
            sf::Vertex(from, sf::Color::Blue),
            sf::Vertex(to, sf::Color::Blue)
        };

        wnd.draw(line, 2, sf::LinesStrip);
    }
    else
    {
        sf::Vertex line[] =
        {
            sf::Vertex(from, sf::Color::Blue),
            sf::Vertex(sf::Vector2f(from.x + (to.x - from.x) / 2.0f, from.y), sf::Color::Blue),
            sf::Vertex(sf::Vector2f(from.x + (to.x - from.x) / 2.0f, to.y), sf::Color::Blue),
            sf::Vertex(to, sf::Color::Blue)
        };

        wnd.draw(line, 4, sf::LinesStrip);
    }


}
