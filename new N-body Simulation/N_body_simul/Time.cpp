#include "Time.h"
#include <iostream>
//http://smok95.tistory.com/193

using namespace std;


Time::Time() //constructor
{
	//initialization: tick with 1.0sec, duration with 10.0sec
	tick = 1.0;
	duration = 10.0;
	timeArr.push_back(0);
}

//destructor??

void Time::mkTimeArr(double duration_) //make time array
{
	if (tick > duration_)//error handling: tick condition
	{
		cout << "Error: The tick(" << tick << "s) is shorter than the duration.";
		return;
	}

	duration = duration_;
	timeArr.clear(); //array initialization
	timeArr.push_back(0);
	for (int i = 1; i <= (int)(duration / tick); i++)//make array of time for duration with the interval of tick
	{
		timeArr.push_back(i * tick);
	}
	if (*(timeArr.end() - 1) != duration) //append final time
	{
		timeArr.push_back(duration);
	}
}

void Time::ct(double tick_) //change times
{
	if (tick_ == 0.0) //error handling: tick is zero
	{
		cout << "Error: The tick(" << tick << "s) is zero.";
		return;
	}
	tick = tick_;
}

void Time::pt() // print current time
{
	cout << "Current Time is " << *(timeArr.end()-1) << "s" << endl;
}

void Time::ru(double duration_)
{
	
}
