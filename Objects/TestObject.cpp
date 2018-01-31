//
// Created by vebis on 26.01.18.
//

#include <GL/gl.h>
#include "TestObject.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>

using namespace std;

void TestObject::loadObjectFromPath(std::string path)
{
    std::string line;
    std::ifstream myfile;
    myfile.open(path);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            //std::cout << line << '\n';
            vector<float> coords;

            string numb;
            Coordinate coord = Coordinate();

            for(int i = 0 ; i <= line.length(); i++)
            {

                if(line[i]== ' ' || (i >= line.length()))
                {

                    float temp = 0;
                    const char* chr = numb.c_str();
                    temp = strtof(chr, nullptr);
                    coord.SetValues(temp);
                    numb.clear();
                    int count = coord.GetCount();
                    if(count == 3)
                    {
                        this->Faces.push_back(coord);
                        coord = Coordinate();
                    }

                }
                else
                {
                    numb.push_back(line[i]);
                }
            }
        }
        myfile.close();
    }

}

void TestObject::drawMe()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.f, 0.f, -200.f); // Move object further away from camera



    glEnd();
}