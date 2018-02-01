//
// Created by vebis on 26.01.18.
//

#include <GL/gl.h>
#include "TestObject.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <cstring>
#include <SFML/Window/Keyboard.hpp>

using namespace std;

bool TestObject::loadOBJ(const char *path)
{
    FILE * file = fopen(path, "r");
    if(file == NULL)
    {
        printf("Impossible to open the file !\n");
        return false;
    }

    while( 1 )
    {
        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        // else : parse lineHeader
        if ( strcmp ( lineHeader, "v" ) == 0 )
        {
            float x, y, z;
            fscanf(file, "%f %f %f\n", &x, &y, &z );
            Coordinate coord;
            coord.SetX(x); coord.SetY(y); coord.SetZ(z);
            this->Vertices.push_back(coord);
        }

        else if ( strcmp( lineHeader, "vt" ) == 0 )
        {
            float x, y;
            fscanf(file, "%f %f %f\n", &x, &y);
            Coordinate coord;
            coord.SetX(x); coord.SetY(y);
            this->UVs.push_back(coord);
        }
        else if ( strcmp( lineHeader, "vn" ) == 0 )
        {
            float x, y, z;
            fscanf(file, "%f %f %f\n", &x, &y, &z );
            Coordinate coord;
            coord.SetX(x); coord.SetY(y); coord.SetZ(z);
            this->Normals.push_back(coord);
        }
        else if ( strcmp( lineHeader, "f" ) == 0 )
        {
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                 &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2],
                                 &normalIndex[2]);
            if (matches != 9) {
                printf("File can't be read by our simple parser : ( Try exporting with other options\n");
                return false;
            }
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            uvIndices.push_back(uvIndex[0]);
            uvIndices.push_back(uvIndex[1]);
            uvIndices.push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }
    }

    /*for(auto coords: this->Faces)
    {
        cout << coords.GetX() << " " << coords.GetY() << " " << coords.GetZ() << endl;
    }*/
}


void TestObject::drawMe()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Handle keyinputs
    if(this->KeyAPressed)
        this->XMovement -= 0.01f;
    if(this->KeyDPressed)
        this->XMovement += 0.01f;
    if(this->KeyWPressed)
        this->ZMovement -= 0.01f;
    if(this->KeySPressed)
        this->ZMovement += 0.01f;

    glTranslatef(0.f + XMovement, 0.f, -5.f + ZMovement); // Move object further away from camera
    //glRotatef(angle * 50, 1.f, 0.f, 0.f);
    //glRotatef(angle * 30, 0.f, 1.f, 0.f);
    //glRotatef(angle * 90, 0.f, 0.f, 1.f);

    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    // For each vertex of each triangle
    /*for(auto &coord: this->Vertices)
    {
        unsigned int vertexIndex = vertexIndices[i];
        vector<Coordinate> vertex = coord;
    }*/
    for(auto &coord: this->Vertices)
    {
        glVertex3f(coord.GetX(), coord.GetY(), coord.GetZ());
    }
    glEnd();

}
