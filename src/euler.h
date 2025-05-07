#ifndef EULER_H
#define EULER_H

class Euler
{
    public:
        Euler(float roll, float pitch, float yaw);
    protected:
        float roll;
        float pitch;
        float yaw;
};
#endif