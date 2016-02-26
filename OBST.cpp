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


	pair<int, int> min(int i, int j, int l, vector <vector <int> > temp) // fonction pour trouver min entre plusieur addition
	{
		int min = 100;
		int mink = -1;
		pair <int, int> p;
		
		for (int k = i+1; k<=j; k++)
		{
			if (min > (temp[i][k - 1] + temp[k][j])) //
			{
				min = (temp[i][k - 1] + temp[k][j]);
				mink = k;
			}
		
		}
		
		p.first = min; // nombre minimal
		p.second = mink; // nombre k qui a trouver le nombre minimal
		return p;
		
		
	}

	void getOptimalPrime() // hahah get it, optimus prime ... transformers.. ha
	{
		vector <vector <int> > pere(elements.size()+1, vector <int>(elements.size()+1)); // table 2d pour mes roots
		vector <vector <int> > sumFrequence(elements.size()+1, vector <int>(elements.size()+1)); // table 2d pour la sum des frequence de differente longeur
		vector <vector <int> > intervalFrequence(elements.size()+1, vector <int>(elements.size()+1)); // frequence d'un noeud plus un autre

		for (unsigned int i = 0; i <= elements.size(); i++)
		{
			for (unsigned int j = 0+i; j <= elements.size(); j++)
			{
				if (i != j && j != elements.size()+1)
					intervalFrequence[i][j] = intervalFrequence[i][j - 1] + elements[j-1].second;
			}
		}
		for (int l = 1; l <= elements.size();l++)
		{
			for (unsigned int i = 0; i < elements.size() + 1; i++)
			{
				int temp = i + l + 1;
				for (unsigned int j = i+l; j < temp; j++)
				{
					if (j < elements.size()+1)
					{
					pair<int, int> p;
					p = min(i, j, l, sumFrequence);
					sumFrequence[i][j] = intervalFrequence[i][j] + p.first;
					pere[i][j] = p.second;
					}

				}
			}
		}
		cout << "cout opptimal est: " << sumFrequence[0][elements.size()] << endl;
		printOBST(0, elements.size(), 0, pere);

	}
	void printOBST(int i, int j,int l, vector <vector<int> > pere)
	{
		if (j <=i)
			return;
		printOBST(pere[i][j] , j, l + 1, pere);
		for (int i = 0; i < l; i++)
			cout << "\t";
		cout << elements[pere[i][j]-1].first << endl;
		printOBST(i, pere[i][j] -1, l + 1, pere);
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
	a.getOptimalPrime(); 
	
	return 0;
}
