//
// Created by vebis on 31.01.18.
//

#ifndef PROJECT_COORDINATE_H
#define PROJECT_COORDINATE_H


class Coordinate
{
public:
    Coordinate() = default;

    void SetX(float x) { this->x = x; }
    void SetY(float y) { this->y = y; }
    void SetZ(float z) { this->z = z; }

    void NormalSetX(float x) { this->nX = x; }
    void NormalSetY(float y) { this->nY = y; }
    void NormalSetZ(float z) { this->nZ = z; }

    void SetValues(float value);

    float GetX();
    float GetY();
    float GetZ();
    float NormalGetX();
    float NormalGetY();
    float NormalGetZ();
    int GetCount(){return count;}

private:
    int count = 0;
    float x;
    float y;
    float z;
    float nX;
    float nY;
    float nZ;

};


#endif //PROJECT_COORDINATE_H
