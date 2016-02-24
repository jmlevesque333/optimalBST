//jean-Michel Levesque A00172309
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

class obst
{
	vector <vector <int> > pere;
	vector <vector <int> > sumFrequence;
	vector <vector <int> > intervalFrequence;
	vector <pair <string, int> > elements;
public:
	obst()
	{}
	void addPair(string name, int frequence)
	{
		elements.push_back(make_pair(name, frequence));
	}
	void GetOptimalPrime()
	{
		
		for (int i = 0; i < elements.size(); i++)
		{
			pere[i][i] = 0;
			sumFrequence[i][i] = 0;
			intervalFrequence[i][i] = 0;

		}
	}

};

int main()
{
	obst a;
	string name;
	string frequence;
	int frequence2;
	fstream file;
	file.open("input.txt");
	while (file >> name)
	{
		file >> frequence;
		frequence2 = stoi(frequence);
		a.addPair(name, frequence2);

	}

	return 0;
}
