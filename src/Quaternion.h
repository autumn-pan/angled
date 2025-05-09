#ifndef QUATERNION_H
#define QUATERNION_H
class Quaternion
{
    public:
        Quaternion(float q1, float q2, float q3, float q4);
        Quaternion* add(Quaternion * q);
        Quaternion* sub(Quaternion * q);
        Quaternion* mult(Quaternion * q);
        Quaternion* mult(float scalar);
    protected:
        float q1;
        float q2;
        float q3;
        float q4;
};

#endif