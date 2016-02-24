#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class obst
{
	node* root;
	int nbOfNodes;
	obst()
	{
		root = NULL;
		nbOfNodes = 0;
	}
	void addNode(string name, int frequence)
	{
		if (nbOfNodes == 0)
			root = new node(name, frequence);
		else
		{

		}
	}


};

class node
{
public:
	string name;
	string racine;
	int frequence;.

	node* left;
	node* right;

	node(string name, int frequence, node* left = NULL, node* right = NULL)
	{
		this->name = name;
		this->frequence = frequence;
		this->left = left;
		this->right = right;
	}
};

int main()
{
	string name;
	string frequence;
	int frequence2;
	obst arbre();
	fstream file;
	file.open("input.txt");
	while (file >> name)
	{
		file >> frequence;
		frequence2 = stoi(frequence);


	}

	return 0;
}
