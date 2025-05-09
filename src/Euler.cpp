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

void Euler::addRoll(float roll)
{
    this->roll += roll;
}
void Euler::addPitch(float pitch)
{
    this->pitch += pitch;
}
void Euler::addYaw(float yaw)
{
    this->yaw += yaw;
}

