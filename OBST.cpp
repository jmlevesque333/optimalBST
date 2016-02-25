//jean-Michel Levesque A00172309
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>
#include <algorithm>

using namespace std;

bool pairCompare(const pair<string, int> a, const pair<string, int> b) {
	return a.first < b.first;
}

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
	void sorting()
	{
		sort(elements.begin(), elements.end());
	}
	void GetOptimusPrime()
	{
		vector <int> temp;
		for (int i = 0; i < elements.size(); i++)
		{
			temp.push_back(-1);
			for (int j = 0; j < elements.size(); i++)
			{	
				pere.push_back(temp);
				sumFrequence.push_back(temp);
				intervalFrequence.push_back(temp);
			}
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
	a.sorting();

	return 0;
}
