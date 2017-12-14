#pragma once
//#include "Particle.h"
#include <vector>

using namespace std;

class Time//make time class
{
private:
	double tick;//time(sec) interval
	vector<double> timeArr;//time array(sec)
	double duration;//time duration


public:
	Time();// construct timetick(sec)//////////////////////////////////////////////////////////////////////////////////////////////////
	void mkTimeArr(double duration_ = 10.0);//make time array/////////////////////////////////////////////////////////////////////////
	void ru(double duration_);///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void ct(double tick_ = 1.0);//change timetick(sec)
	void pt();//print the current time

};