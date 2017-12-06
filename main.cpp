#include <thread>

#include "Control.h"
#include "Force.h"
#include "Particle.h"
#include "Set.h"
#include "Time.h"/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////수정


using namespace std;

map<int, Particle> all; //global variable map!

void parser(istream& is);

int main() {
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	parser(cin); //input a 'console in' object 
}

void parser(istream& is) {
	Time *timer = new Time();///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////수정
	thread tw1 = timer->TimerThread();/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////수정

	cout << "Timer Started" << endl;//////////////////////////////////////////////////////////////////////////////////////////////////////////수정
	cout << "Enter a command: ";/////////////////////////////////////////////////////////////////////////////////////
	Particle *particle_all= new Particle; 
	map<int, Particle> all; //global variable map!
	for (string line; getline(is, line); ) { //get a line of cin
		if (line == "qq")
			break;
		istringstream iss{ line }; //?
		vector<string> words{ istream_iterator<string> {iss}, //?
			istream_iterator<string> {} }; //?
		for (int i = 0; i < words.size(); ++i)
		{
			if (words[0] == "ap") //if command is "ap"(add particle)
			{
				double *temp=new double[words.size()];
				for (int j = 0; j < words.size()-1; ++j)
					temp[j] = stod(words[j+1], 0);
				particle_all->var_set(temp);
				//add key of result to all
				delete(temp);
				cout << "Particle " << words[1] << " added \n\n";
				break;
			}
			else if (words[0] == "pp")
			{
				particle_all->print_particle(stoi(words[1]));
				break;
			}
			else if (words[0] == "dp")
			{
				particle_all->delete_particle(stoi(words[1]));
				break;
			}
			else if (words[0] == "ct")/////////////////////////////////////////////////////////////////////////////////////////////////수정
			{
				timer->ct(stod(words[1]));////////////////////////////////////////////////////////////////////////////////////////////////
			}
			else if (words[0] == "pt")////////////////////////////////////////////////////////////////////////////////////////////////////////////
			{
				timer->pt();///////////////////////////////////////////////////////////////////////////////////////////////////////////////
			}
		}
		cout << "Enter a command: ";
	}
	delete(particle_all);
	delete(timer);
}