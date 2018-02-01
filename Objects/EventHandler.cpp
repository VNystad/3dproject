//
// Created by vebis on 01.02.18.
//

#include <GL/gl.h>
#include "EventHandler.h"


void EventHandler::HandleEvent(sf::Event event, bool &running, TestObject *testObject)
{

    if (event.type == sf::Event::MouseMoved)
    {
        
    }
    else if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::A)
            testObject->SetKeyAPressed(true);

        else if (event.key.code == sf::Keyboard::D)
            testObject->SetKeyDPressed(true);

        else if (event.key.code == sf::Keyboard::W)
            testObject->SetKeyWPressed(true);

        else if (event.key.code == sf::Keyboard::S)
            testObject->SetKeySPressed(true);

        else if (event.key.code == sf::Keyboard::Escape)
            running = false;
    }
    else if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::A)
            testObject->SetKeyAPressed(false);

        else if (event.key.code == sf::Keyboard::D)
            testObject->SetKeyDPressed(false);

        else if (event.key.code == sf::Keyboard::W)
            testObject->SetKeyWPressed(false);

        else if (event.key.code == sf::Keyboard::S)
            testObject->SetKeySPressed(false);

    }
    else if (event.type == sf::Event::Resized)
    {
        // adjust the viewport when the window is resized
        glViewport(0, 0, event.size.width, event.size.height);
    }
}