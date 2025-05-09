#ifndef EULER_H
#define EULER_H

class Euler
{
    public:
        Euler(float roll, float pitch, float yaw);

        void add(Euler * e);
        void sub(Euler * e);
        void mult(Euler * e);
        void mult(float scalar);

        void addRoll(float roll);
        void addPitch(float pitch);
        void addYaw(float yaw);
    protected:
        float roll;
        float pitch;
        float yaw;
};
#endif