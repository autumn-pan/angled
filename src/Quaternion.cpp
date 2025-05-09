#include "Quaternion.h"
#include <cmath>

Quaternion::Quaternion(float q1, float q2, float q3, float q4)
{
    this->q1 = q1;
    this->q2 = q2;
    this->q3 = q3;
    this->q4 = q4;
}

Quaternion* Quaternion::add(Quaternion * q)
{
    return new Quaternion(this->q1 + q->q1, this->q2 + q->q2, this->q3 + q->q3, this->q4 + q->q4);
}

Quaternion* Quaternion::sub(Quaternion * q)
{
    return new Quaternion(this->q1 - q->q1, this->q2 - q->q2, this->q3 - q->q3, this->q4 - q->q4);
}

Quaternion* Quaternion::mult(Quaternion * q)
{
    return new Quaternion(
        this->q1 * q->q1 - this->q2 * q->q2 - this->q3 * q->q3 - this->q4 * q->q4,
        this->q1 * q->q2 + this->q2 * q->q1 + this->q3 * q->q4 - this->q4 * q->q3,
        this->q1 * q->q3 - this->q2 * q->q4 + this->q3 * q->q1 + this->q4 * q->q2,
        this->q1 * q->q4 + this->q2 * q->q3 - this->q3 * q->q2 + this->q4 * q->q1
    );
}

Quaternion* Quaternion::mult(float scalar)
{
    return new Quaternion(this->q1 * scalar, this->q2 * scalar, this->q3 * scalar, this->q4 * scalar);
}

// Rotation helper functions
Quaternion* pointToQuaternion(float x, float y, float z)
{
    return new Quaternion(0, x, y, z);
}

Quaternion* Quaternion::inverse()
{
    return new Quaternion(this->q1, -this->q2, -this->q3, -this->q4);
}

Quaternion* Quaternion::normalize()
{
    float norm = sqrt(this->q1 * this->q1 + this->q2 * this->q2 + this->q3 * this->q3 + this->q4 * this->q4);
    return new Quaternion(this->q1 / norm, this->q2 / norm, this->q3 / norm, this->q4 / norm);
}

Quaternion* getRotationQuaternion(float roll, float pitch, float yaw)
{
    //Calculate half angles
    //cy = cos(yaw * 0.5);
    //sy = sin(yaw * 0.5);
    //etc.

    float cy = cos(yaw * 0.5);
    float sy = sin(yaw * 0.5);
    float cp = cos(pitch * 0.5);
    float sp = sin(pitch * 0.5);
    float cr = cos(roll * 0.5);
    float sr = sin(roll * 0.5);

    // The rotation quaternion is calculated as follows:
    return new Quaternion(
        cr * cp * cy + sr * sp * sy,
        sr * cp * cy - cr * sp * sy,
        cr * sp * cy + sr * cp * sy,
        cr * cp * sy - sr * sp * cy
    );
}

Quaternion* Quaternion::rotate(float roll, float pitch, float yaw, float x, float y, float z)
{
    Quaternion* q = getRotationQuaternion(roll, pitch, yaw);
    Quaternion* p = pointToQuaternion(x, y, z);
    Quaternion* result = q->mult(p)->mult(q->inverse());
    delete q;
    delete p;
    return result;
}