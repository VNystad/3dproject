//
// Created by vebis on 26.01.18.
//

#ifndef PROJECT_TESTOBJECT_H
#define PROJECT_TESTOBJECT_H


#include "CollidableObject.h"
#include "string"

class TestObject : public CollidableObject
{

public:
    TestObject() = default;

    void loadObjectFromPath(std::string path);
    void drawMe();
    double GetGravity() { return gravity; };

private:
    std::vector<Coordinate> Faces;
    double gravity = 1;
    double angle = 0.3;
};


#endif //PROJECT_TESTOBJECT_H
