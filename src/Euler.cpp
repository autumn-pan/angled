#include "Euler.h"

Euler::Euler(double roll, double pitch, double yaw)
{
    this->roll = roll;
    this->pitch = pitch;
    this->yaw = yaw;
}

Euler* Euler::add(Euler *e)
{
    return new Euler(this->roll + e->roll, this->pitch + e->pitch, this->yaw + e->yaw);
}

Euler* Euler::sub(Euler *e)
{
    return new Euler(this->roll - e->roll, this->pitch - e->pitch, this->yaw - e->yaw);
}

Euler* Euler::mult(Euler *e)
{
    return new Euler(this->roll * e->roll, this->pitch * e->pitch, this->yaw * e->yaw);
}

Euler* Euler::mult(double scalar)
{
    return new Euler(this->roll * scalar, this->pitch * scalar, this->yaw * scalar);
}

void Euler::addRoll(double roll)
{
    this->roll += roll;
}

void Euler::addPitch(double pitch)
{
    this->pitch += pitch;
}

void Euler::addYaw(double yaw)
{
    this->yaw += yaw;
}

double Euler::getRoll()
{
    return this->roll;
}

double Euler::getPitch()
{
    return this->pitch;
}
double Euler::getYaw()
{
    return this->yaw;
}
