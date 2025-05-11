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

        Quaternion* inverse();
        Quaternion* normalize();


        Quaternion* rotate(float roll, float pitch, float yaw, float x, float y, float z);

        float getQ1();
        float getQ2();
        float getQ3();
        float getQ4();
    private:
        float q1;
        float q2;
        float q3;
        float q4;
};

Quaternion* pointToQuaternion(float x, float y, float z);
Quaternion* getRotationQuaternion(float roll, float pitch, float yaw);

#endif