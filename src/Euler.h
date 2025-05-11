#ifndef EULER_H
#define EULER_H

class Euler
{
    public:
        Euler(double roll, double pitch, double yaw);

        Euler* add(Euler * e);
        Euler* sub(Euler * e);
        Euler* mult(Euler * e);
        Euler* mult(double scalar);

        void addRoll(double roll);
        void addPitch(double pitch);
        void addYaw(double yaw);

        double getRoll();
        double getPitch();
        double getYaw();
    private:
        double roll;
        double pitch;
        double yaw;
};
#endif