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

    void SetValues(float value);

    float GetX();
    float GetY();
    float GetZ();
    int GetCount(){return count;}

private:
    int count = 0;
    float x;
    float y;
    float z;

};


#endif //PROJECT_COORDINATE_H
