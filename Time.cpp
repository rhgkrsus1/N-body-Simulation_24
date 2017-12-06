#include "Time.h"
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;


Time::Time(double tick_) //constructor
{
	tick = tick_;
}

thread Time::TimerThread()
{
	return thread([=] { Timer_f(); }); //?
}

void Time::Timer_f() //timer function
{
	while(true)
	{
		this_thread::sleep_for(chrono::microseconds((int)(tick * 1000000)));
		cTime += tick;
		//cout << cTime << endl;
	}
}

void Time::ct(double tick_) //change times
{
	tick = tick_;
}

void Time::pt() // print current time
{
	cout << "Time: " << cTime << "s" << endl;
}