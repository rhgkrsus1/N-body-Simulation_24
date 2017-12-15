#include "Control.h"
#include "Force.h"
#include "Particle.h"
#include "Set.h"
#include "Time.h"///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <memory>

using namespace std;

//map<int, Particle> all; //global variable map!///////////////////////////////////////////////////////////////////////////

void parser(istream& is);

int main() {
	std::cout << "Enter a command: ";
	parser(cin);
}

void parser(istream& is) {

	unique_ptr<Time> timer{ new Time() };//smart pointer //////////////////////////////////////////////////////////////////수정

	unique_ptr<Particle> particle_all{ new Particle };/////////////////////////////////////////////////////////////////수정

	unique_ptr<Set> set_all{ new Set };////////////////////////////////////////////////////////////////////////////////////수정

	set_all->big_set_make(0, set_all.get());	//make default set///////////////////////////////////////////////수정

	//map<int, Particle> all; //map/////////////////////////////////////////////////////////////////////////////////수정

	//map<int, std::map<int, std::map<int, Particle_s> > > all_set; //map saves set/////////////////////////////////수정

	for (string line; getline(is, line); ) {
		if (line == "qq")
			break;
			
		istringstream iss{ line };
		vector<string> words{ istream_iterator<string> {iss},
			istream_iterator<string> {} };
		////////////////////////////////////////////////////////////////////////////////////////////////수정
		while (true)
		{
			if (words[0] == "ap") //if command is "ap"(add particle)//////////////////////////////////수정
			{
				unique_ptr<double[]> temp{ new double[words.size() - 1] };
				for (int j = 0; j < words.size() - 1; ++j)
					temp[j] = stod(words[j + 1]);
				particle_all->var_set(temp.get());
				//add key of result to all
				std::cout << "Particle " << words[1] << " added \n\n";

				set_all->indiv_set_make(0, stoi(words[1]), particle_all.get(), set_all.get());	//send to default set
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
			else if (words[0] == "as")//////////////////////////////////////////////////////////////////////////////////////수정
			{
				if (stoi(words[1]) == 0)
				{
					std::cout << "You cannot make the default set." << endl << endl;
					break;
				}
				set_all->big_set_make(stoi(words[1]), set_all.get());/////////////////////////////////////////////////////수정
				std::cout << "Set " << words[1] << " added \n\n";
				break;
			}
			else if (words[0] == "ae")/////////////////////////////////////////////////////////////////////////수정
			{
				set_all->delete_p_to_s(0, stoi(words[2]));	//delete from default set

				set_all->indiv_set_make(stoi(words[1]), stoi(words[2]), particle_all.get(), set_all.get());
				std::cout << "Particle " << words[2] << " added to set " << words[1] << "\n\n";
				break;
			}
			else if (words[0] == "ps")
			{
				set_all->print_set(stoi(words[1]));
				break;
			}
			else if (words[0] == "de")
			{
				if (stoi(words[1]) == 0)
				{
					std::cout << "You cannot delete a particle from default set." << endl;
					break;
				}
				set_all->delete_p_to_s(stoi(words[1]), stoi(words[2]));////////////////////////////////////////////수정
				std::cout << "Particle " << words[2] << " deleted from Set" << words[1] << "\n\n";

				set_all->indiv_set_make(0, stoi(words[2]), particle_all.get(), set_all.get());	//send to default set
				break;
			}
			else if (words[0] == "af")
			{
				set_all->impose_force(stoi(words[1]), stoi(words[2]), stod(words[3]), stod(words[4]));
				std::cout << "Force " << words[1] << "is now imposed on Set " << words[2] << "!\n\n";
				break;
			}
			else if (words[0] == "pf")
			{
				set_all->print_force();
				break;
			}
			else if (words[0] == "df")
			{
				set_all->delete_force(stoi(words[1]));
				std::cout << "Force " << words[1] << " deleted!";
				break;
			}
			else if (words[0] == "ct")	//change timetick command
			{
				timer->ct(stod(words[1]));
				std::cout << "Timetick is changed into " << words[1] << "(sec)." << endl << endl;
				break;
			}
			else if (words[0] == "pt")	//print time command
			{
				timer->pt();
				std::cout << endl;
				break;
			}
			else if (words[0] == "ru")	//run commnad
			{
				timer->ru(stod(words[1]), set_all.get());
				std::cout << "Current Time is " << stod(words[1]) << "s" << endl;
				map<int, map<int, map<int, Particle_s>::iterator>>::iterator it_all_set;
				for (it_all_set = (set_all->all_set_info).begin(); it_all_set != (set_all->all_set_info).end(); it_all_set++)	//scan all set
				{
					int set_num = it_all_set->first;	//set number
					set_all->print_set(set_num);
				}
				break;
			}
			else if (words[0] == "rv")	//run with visualization command
			{
				timer->vis = true;
				timer->ru(stod(words[1]), set_all.get());
				timer->vis = false;
				break;
			}
			else if (words[0] == "cp")	//particle fixatioin command
			{
				if (words[2] == "true")
				{
					particle_all->part_info[stoi(words[1])].cp = true;
					std::cout << "Particle " << words[1] << " is free now." << endl << endl;
				}
				else if (words[2] == "false")
				{
					particle_all->part_info[stoi(words[1])].cp = false;
					std::cout << "Particle " << words[1] << " is fixed now." << endl << endl;
				}
				break;
			}
			else if (words[0] == "cg")	//gravity on/off command
			{
				if (words[1] == "true")
				{
					timer->cg = true;
					std::cout << "Gravity is now on." << endl << endl;
				}
				else if (words[1] == "false")
				{
					timer->cg = false;
					std::cout << "Gravity is now off." << endl << endl;
				}
				break;
			}
		}

		std::cout << "Enter a command: ";
	}
}