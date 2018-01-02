#include "PID.h"
#include <iostream>


using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

    Kp = Kp;
    Ki = Ki;
    Kd = Kd;

    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;

}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
    std::cout << "d_error: " << d_error << " p_error: " << p_error << " i_error: " << i_error << std::endl;


}

double PID::TotalError() {

    double total_error = (p_error * Kp + i_error * Ki + d_error * Kd);
    //std::cout << "total_error: " << total_error << std::endl;
    std::cout << "d_total: " << d_error * Kd << " p_total: " << p_error * Kp << " i_total: " << i_error * Ki << std::endl;
    return total_error;
}

