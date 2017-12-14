#include "Time.h"
#include <iostream>

using namespace std;

Time::Time() //constructor
{
	//initialization: tick with 1.0sec, cur_t with 0.0sec, vis with false
	tick = 1.0;
	cur_t = 0.0;
	bool vis = false;
}

void Time::ct(double tick_) //change timetick(sec)
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
	cout << "Current Time is " << cur_t << "s" << endl;
}


void Time::ru(double duration, Set* all_set)
{
	cur_t = 0.0;	//initiallize current time
	double ne_t = 0.0;
	while (true)
	{
		ne_t = (cur_t + tick < duration ? cur_t + tick : duration);	//time tick & checking operation for last time
		for (map<int, map<int, Particle_s>>::iterator it_set = (all_set->all_set_info).begin(); it_set != (all_set->all_set_info).end(); it_set++)	//scan all set
		{
			//force 문제: force는 새로 생성되어 set에 지정할수만 있고 자체로 생성될 수 없음. 그래서 지정하는 set에 
			//force가 이미 있으면 기존의 force_info의 force를 지우고 새로 만들어야 되는데 그런 과정이 없음.
			//또한 force 여러개에 set이 하나가 지정될 수 있음.

			int set_num = it_set->first;	//set number
			map<int, Particle_s> i_set = it_set->second;	//current set
			//recode force
			//map<int, std::map<int, Force *>>::iterator it_i_force = (c_set->force_info).find(set_num);
			//map<int, Force *>::iterator
			double force_x = 0.0;
			double force_y = 0.0;

			for (map<int, Particle_s>::iterator it_pa = i_set.begin(); it_pa != i_set.end(); ++it_pa)	//scan particle
			{
				//recode grav
				double grav_x = 0.0;
				double grav_y = 0.0;
				//end
				int pa_num = it_pa->first;
				Particle_s cur_pa_struct = it_pa->second;

				double cur_v_x = cur_pa_struct.velocity[0];	//current value
				double cur_v_y = cur_pa_struct.velocity[1];
				double cur_p_x = cur_pa_struct.position[0];
				double cur_p_y = cur_pa_struct.position[1];
				double m = cur_pa_struct.mass;
				
				double ne_v_x = ((force_x + grav_x) / m)*tick + cur_v_x;	//next value
				double ne_v_y = ((force_y + grav_y) / m)*tick + cur_v_y;
				double ne_p_x = ne_v_x*tick + cur_p_x;
				double ne_p_y = ne_v_y*tick + cur_p_y;

				Particle_s ne_pa_struct;	//construct struct
				ne_pa_struct.velocity[0] = ne_v_x;
				ne_pa_struct.velocity[1] = ne_v_y;
				ne_pa_struct.position[0] = ne_p_x;
				ne_pa_struct.position[1] = ne_p_y;


			}
		}
		cur_t = ne_t;
		if (cur_t == duration)
			break;
	}
}


