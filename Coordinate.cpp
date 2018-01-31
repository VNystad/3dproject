//
// Created by vebis on 31.01.18.
//

#include "Coordinate.h"

/*Coordinate::Coordinate(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}*/

void Coordinate::SetValues(float value)
{
    count ++;
    if(count == 1)
        this->x = value;
    else if(count == 2)
        this->y = value;
    else
        this->z = value;
}

float Coordinate::GetX()
{
    return x;
}

float Coordinate::GetY()
{
    return y;
}

float Coordinate::GetZ()
{
    return z;
}