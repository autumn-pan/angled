#ifndef QUATERNION_H
#define QUATERNION_H
class Quaternion
{
    public:
        Quaternion(double q1, double q2, double q3, double q4);
        Quaternion* add(Quaternion * q);
        Quaternion* sub(Quaternion * q);
        Quaternion* mult(Quaternion * q);
        Quaternion* mult(double scalar);

        Quaternion* inverse();
        Quaternion* normalize();


        Quaternion* rotate(double roll, double pitch, double yaw, double x, double y, double z);

        double getQ1();
        double getQ2();
        double getQ3();
        double getQ4();
        
    private:
        double q1;
        double q2;
        double q3;
        double q4;
};

Quaternion* pointToQuaternion(double x, double y, double z);
Quaternion* getRotationQuaternion(double roll, double pitch, double yaw);

#endif