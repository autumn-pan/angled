#include "Quaternion.h"

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