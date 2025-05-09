#include "Euler.h"

Euler::Euler(float roll, float pitch, float yaw)
{
    this->roll = roll;
    this->pitch = pitch;
    this->yaw = yaw;
}

void Euler::add(Euler * e)
{
    this->roll += e->roll;
    this->pitch += e->pitch;
    this->yaw += e->yaw;
}

void Euler::sub(Euler * e)
{
    this->roll -= e->roll;
    this->pitch -= e->pitch;
    this->yaw -= e->yaw;
}

void Euler::mult(Euler * e)
{
    this->roll *= e->roll;
    this->pitch *= e->pitch;
    this->yaw *= e->yaw;
}

void Euler::mult(float scalar)
{
    this->roll *= scalar;
    this->pitch *= scalar;
    this->yaw *= scalar;
}

