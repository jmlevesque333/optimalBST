//jean-Michel Levesque A00172309
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

class obst
{
	
	vector <pair <string, int> > elements;
public:
	obst()
	{

		
	}
	void addPair(string name, int frequence)
	{
		elements.push_back(make_pair(name, frequence));
	}

	pair<int, int> min(int i, int j, vector <vector <int> > temp)
	{
		int min = 100;
		int mink = -1;
		for (int k = i; k<=j; k++)
		{
			if (min > (temp[i][k - 1] + temp[k+1][j]))
			{
				min = (temp[i][k - 1] + temp[k+1][j]);
				mink = k;
			}
				
		}
		pair <int, int> p;
		p.first = min;
		p.second = mink;
		return p;
	}

	void getOptimusPrime()
	{

		vector <vector <int> > pere(elements.size()+1, vector <int>(elements.size()+1));
		vector <vector <int> > sumFrequence(elements.size()+1, vector <int>(elements.size()+1));
		vector <vector <int> > intervalFrequence(elements.size()+1, vector <int>(elements.size()+1));

		for (unsigned int i = 0; i <= elements.size(); i++)
		{
			for (unsigned int j = 0+i; j <= elements.size(); j++)
			{
				if (i != j && j != elements.size()+1)
					intervalFrequence[i][j] = intervalFrequence[i][j - 1] + elements[j-1].second;
			}
		}
		for (unsigned int i = 0; i < elements.size()+1; i++)
		{
			for (unsigned int j = 0; j < elements.size()+1; j++)
			{
				if (i != j)
				{
					pair<int, int> p;
					p = min(i, j, sumFrequence);
					sumFrequence[i][j] = intervalFrequence[i][j] +p.first;
					pere[i][j] = p.second;

				}
			}

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
	a.getOptimusPrime();

	return 0;
}
