#include  "../include/Quaternion.h"
#include <cmath>

Quaternion::Quaternion(double q1, double q2, double q3, double q4)
{
    this->q1 = q1;
    this->q2 = q2;
    this->q3 = q3;
    this->q4 = q4;
}

Quaternion *Quaternion::add(Quaternion *q)
{
    return new Quaternion(this->q1 + q->q1, this->q2 + q->q2, this->q3 + q->q3, this->q4 + q->q4);
}

Quaternion *Quaternion::sub(Quaternion *q)
{
    return new Quaternion(this->q1 - q->q1, this->q2 - q->q2, this->q3 - q->q3, this->q4 - q->q4);
}

Quaternion *Quaternion::mult(Quaternion *q)
{
    return new Quaternion(
        this->q1 * q->q1 - this->q2 * q->q2 - this->q3 * q->q3 - this->q4 * q->q4,
        this->q1 * q->q2 + this->q2 * q->q1 + this->q3 * q->q4 - this->q4 * q->q3,
        this->q1 * q->q3 - this->q2 * q->q4 + this->q3 * q->q1 + this->q4 * q->q2,
        this->q1 * q->q4 + this->q2 * q->q3 - this->q3 * q->q2 + this->q4 * q->q1);
}

Quaternion *Quaternion::mult(double scalar)
{
    return new Quaternion(this->q1 * scalar, this->q2 * scalar, this->q3 * scalar, this->q4 * scalar);
}

// Rotation helper functions
Quaternion *pointToQuaternion(double x, double y, double z)
{
    return new Quaternion(0, x, y, z);
}

Quaternion *Quaternion::inverse()
{
    return new Quaternion(this->q1, -this->q2, -this->q3, -this->q4);
}

Quaternion *Quaternion::normalize()
{
    double norm = sqrt(this->q1 * this->q1 + this->q2 * this->q2 + this->q3 * this->q3 + this->q4 * this->q4);
    return new Quaternion(this->q1 / norm, this->q2 / norm, this->q3 / norm, this->q4 / norm);
}

Quaternion *getRotationQuaternion(double roll, double pitch, double yaw)
{
    // Calculate half angles
    // cy = cos(yaw * 0.5);
    // sy = sin(yaw * 0.5);
    // etc.

    double cy = cos(yaw * 0.5);
    double sy = sin(yaw * 0.5);
    double cp = cos(pitch * 0.5);
    double sp = sin(pitch * 0.5);
    double cr = cos(roll * 0.5);
    double sr = sin(roll * 0.5);

    // The rotation quaternion is calculated as follows:
    return new Quaternion(
        cr * cp * cy + sr * sp * sy,
        sr * cp * cy - cr * sp * sy,
        cr * sp * cy + sr * cp * sy,
        cr * cp * sy - sr * sp * cy);
}

Quaternion *Quaternion::rotate(double roll, double pitch, double yaw, double x, double y, double z)
{
    Quaternion *q = getRotationQuaternion(roll, pitch, yaw);
    Quaternion *p = pointToQuaternion(x, y, z);
    Quaternion *result = q->mult(p)->mult(q->inverse());
    delete q;
    delete p;
    return result;
}

double Quaternion::getQ1()
{
    return this->q1;
}
double Quaternion::getQ2()
{
    return this->q2;
}
double Quaternion::getQ3()
{
    return this->q3;
}
double Quaternion::getQ4()
{
    return this->q4;
}