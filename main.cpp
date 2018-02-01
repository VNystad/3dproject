#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>
#include "Objects/TestObject.h"
#include "Objects/EventHandler.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL SFML", sf::Style::Default, sf::ContextSettings(24));

    // For later use, measuring fps
    sf::Clock clock;
    // activate the window
    window.setActive(true);

    // Set color and depth clear value
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, 1.f, 1.f, 300.0f);//fov, aspect, zNear, zFar

    TestObject* myobject = new TestObject();
    //myobject->loadObjectFromPath("teddy.txt");
    myobject->loadOBJ("Models/untitled.obj");


    // load resources, initialize the OpenGL states, ...

    bool rotate=true;
    //myobject->angle = clock.getElapsedTime().asSeconds();

    // run the main loop
    bool running = true;
    EventHandler* eventHandler = new EventHandler();
    while (running)
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            eventHandler->HandleEvent(event, running, myobject);
        }

        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // draw...

        myobject->drawMe();
        /*if(rotate){
            myobject->angle = clock.getElapsedTime().asSeconds();
        }*/

        // Apply some transformations for the cube
        /*glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);

        if(rotate){
            angle = clock.getElapsedTime().asSeconds();
        }
        glRotatef(angle * 50, 1.f, 0.f, 0.f);
        glRotatef(angle * 30, 0.f, 1.f, 0.f);
        glRotatef(angle * 90, 0.f, 0.f, 1.f);

        glBegin(GL_QUADS);

        glColor3f(1,0,0);
        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f(-50.f,  50.f, -50.f);
        glVertex3f( 50.f,  50.f, -50.f);
        glVertex3f( 50.f, -50.f, -50.f);

        glColor3f(1,1,0);
        glVertex3f(-50.f, -50.f, 50.f);
        glVertex3f(-50.f,  50.f, 50.f);
        glVertex3f( 50.f,  50.f, 50.f);
        glVertex3f( 50.f, -50.f, 50.f);

        glColor3f(1,0,1);
        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f(-50.f,  50.f, -50.f);
        glVertex3f(-50.f,  50.f,  50.f);
        glVertex3f(-50.f, -50.f,  50.f);

        glColor3f(0,0,1);
        glVertex3f(50.f, -50.f, -50.f);
        glVertex3f(50.f,  50.f, -50.f);
        glVertex3f(50.f,  50.f,  50.f);
        glVertex3f(50.f, -50.f,  50.f);

        glColor3f(1,1,1);
        glVertex3f(-50.f, -50.f,  50.f);
        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f( 50.f, -50.f, -50.f);
        glVertex3f( 50.f, -50.f,  50.f);

        glColor3f(1,1,1);
        glVertex3f(-50.f, 50.f,  50.f);
        glVertex3f(-50.f, 50.f, -50.f);
        glVertex3f( 50.f, 50.f, -50.f);
        glVertex3f( 50.f, 50.f,  50.f);

        glEnd();*/


        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    // release resources...

    return 0;
}