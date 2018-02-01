//
// Created by vebis on 01.02.18.
//

#ifndef PROJECT_EVENTHANDLER_H
#define PROJECT_EVENTHANDLER_H


#include <SFML/Window/Event.hpp>
#include "TestObject.h"

class EventHandler
{
public:
    EventHandler() = default;
    void HandleEvent(sf::Event event, bool &running, TestObject* testObject);

};


#endif //PROJECT_EVENTHANDLER_H
