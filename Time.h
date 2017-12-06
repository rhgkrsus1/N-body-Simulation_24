#pragma once
#include <thread>/////////////////////////////////////////////////////////////////////////

using namespace std;

class Time//make time class
{
private:
	double tick;//time(sec) interval
	double cTime = 0.0;//current time(sec)


public:
	Time(double tick_ = 1.0);// construct timetick(sec)
	//timer thread
	thread TimerThread();//////////////////////////////////////////////////////////////
	//timer function
	void Timer_f();/////////////////////////////////////////////////////////////////////
	void ct(double tick_);//change timetick(sec)
	void pt();//print the current time

};