#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) 
{
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	//Initializing proportional, integral, derivative errors to zero.
	this->p_error = 0.0;
	this->i_error = 0.0;
	this->d_error = 0.0;
}

void PID::UpdateError(double cte) 
{
	// derivative error: is the difference between the old cte (p_error) and the new cte
	d_error = cte - p_error;
	// proportional error: is the cte value
	p_error = cte;
	// integral error: is the sum of all cte values
	i_error += cte;
}

double PID::TotalError() 
{
	return (-Kp * p_error - Ki * i_error - Kd * d_error);
}