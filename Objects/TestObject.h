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

    bool loadOBJ(const char * path);
    void drawMe();

    void SetKeyAPressed(bool pressed) { this->KeyAPressed = pressed; }
    void SetKeyDPressed(bool pressed) { this->KeyDPressed = pressed; }
    void SetKeyWPressed(bool pressed) { this->KeyWPressed = pressed; }
    void SetKeySPressed(bool pressed) { this->KeySPressed = pressed; }

    void ChangeAngleFromMouseMovement(float angle) { this->Angle +=angle; }

    /*
    bool GetKeyAPressed(){ return KeyAPressed; }
    bool GetKeyDPressed(){ return KeyDPressed; }
    bool GetKeyWPressed(){ return KeyWPressed; }
    bool GetKeySPressed(){ return KeySPressed; }
    */

    double GetGravity() { return Gravity; };

private:
    float Angle;

    bool KeyAPressed = false;
    float XMovement = 0;
    bool KeyDPressed = false;

    bool KeyWPressed = false;
    float ZMovement = 0;
    bool KeySPressed = false;

    double Gravity = 1;

    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    std::vector<Coordinate> UVs;
    std::vector<Coordinate> Normals;
    std::vector<Coordinate> Vertices;
};


#endif //PROJECT_TESTOBJECT_H
