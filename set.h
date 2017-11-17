#include <string> //string class for set class
#include "particle.h"// particle class for set class
#include "force.h"// particle class for set class

using namespace std;

class set//make a set of particles
{
private:
	particle objParticle[];//particle instance
	force objForce[];//force instance
	//string setName;// name of a set

public:
	set();//constructor
	void ps();//print informaiton of the set
	void as();//make a set
	void ae(particle objParticle_);//add a particle to the set
	void de(particle objParticle_);//delete a particle from the set
	void af(force objForce_, double xForce, double yForce);//add a force to the set whose size is given as a vector (xForce, yForce)
};

class time//make time class
{
private:
	double cTime;//current time
	double tick;//time(sec) interval

public:
	time(double tick_ = 1.0);// construct timetick(sec)
	void ct(double tick_);//change timetick(sec)
	void pt();//print the current time

};