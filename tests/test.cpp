#include "../src/Euler.h"
#include "../src/Quaternion.h"
#include "../src/Matrix.h"

#include <iostream>
#include <cmath>

int main()
{
    // Test Quaternion class
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(5, 6, 7, 8);

    std::cout << "Quaternion Addition: " << std::endl;
    Quaternion* q3 = q1.add(&q2);
    std::cout << q3->getQ1() << " " << q3->getQ2() << " " << q3->getQ3() << " " << q3->getQ4() << std::endl;
    std::cout << "Expected: 6 8 10 12" << std::endl;

    std::cout << "Quaternion Subtraction: " << std::endl;
    Quaternion* q4 = q1.sub(&q2);
    std::cout << q4->getQ1() << " " << q4->getQ2() << " " << q4->getQ3() << " " << q4->getQ4() << std::endl;
    std::cout << "Expected: -4 -4 -4 -4" << std::endl;

    std::cout << "Quaternion Multiplication: " << std::endl;
    Quaternion* q5 = q1.mult(&q2);
    std::cout << q5->getQ1() << " " << q5->getQ2() << " " << q5->getQ3() << " " << q5->getQ4() << std::endl;
    std::cout << "Expected: -60 12 30 24" << std::endl;

    std::cout << "Quaternion Scalar Multiplication: " << std::endl;
    Quaternion* q6 = q1.mult(2);
    std::cout << q6->getQ1() << " " << q6->getQ2() << " " << q6->getQ3() << " " << q6->getQ4() << std::endl;
    std::cout << "Expected: 2 4 6 8" << std::endl;

    std::cout << "Quaternion Inverse: " << std::endl;
    Quaternion* q7 = q1.inverse();
    std::cout << q7->getQ1() << " " << q7->getQ2() << " " << q7->getQ3() << " " << q7->getQ4() << std::endl;
    std::cout << "Expected: 1 -2 -3 -4" << std::endl;

    std::cout << "Quaternion Normalize: " << std::endl;
    Quaternion* q8 = q1.normalize();
    std::cout << q8->getQ1() << " " << q8->getQ2() << " " << q8->getQ3() << " " << q8->getQ4() << std::endl;
    std::cout << "Expected: 0.182574 0.365148 0.547723 0.730297" << std::endl;


    std::cout << "Quaternion Point to Quaternion: " << std::endl;
    Quaternion* qPoint = pointToQuaternion(1, 2, 3);
    std::cout << qPoint->getQ1() << " " << qPoint->getQ2() << " " << qPoint->getQ3() << " " << qPoint->getQ4() << std::endl;
    std::cout << "Expected: 0 1 2 3" << std::endl;

    std::cout << "Quaternion Rotation: " << std::endl;
    Quaternion* q9 = q1.rotate(0.1, 0.2, 0.3, 1, 0, 0);
    std::cout << q9->getQ1() << " " << q9->getQ2() << " " << q9->getQ3() << " " << q9->getQ4() << std::endl;
    std::cout << "Expected: 0.877582 0.0 0.479426 0.0" << std::endl;

    delete q3;
    delete q4;
    delete q5;
    delete q6;
    delete q7;
    delete q8;
    delete q9;


    return 0;
}