#include "Set.h"

using namespace std;

class Time//make time class
{
private:
	double tick;//time(sec) interval
	double cur_t;

public:
	bool vis;//boolean for visualization

	Time();// construct timetick(sec)//////////////////////////////////////////////////////////////////////////////////////////////////
	void ru(double duration, Set* all_set);///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void ct(double tick_ = 1.0);//change timetick(sec)
	void pt();//print the current time

};