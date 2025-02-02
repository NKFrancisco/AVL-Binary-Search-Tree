// BSTStartProject.cpp : Defines the entry point for the console application.
//

#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <sstream>

#include "BSTree.h"
#include "ComputerScientist.h"

vector<string> split(const string &s, char delim) {
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}

vector<ComputerScientist*> load(const string &filename) {
	vector<ComputerScientist*> list;
	std::ifstream file(filename);

	std::string str;
	while (std::getline(file, str))
	{
		vector<string> tokens = split(str, ',');
		
		list.push_back(new ComputerScientist(tokens[1], tokens[2], tokens[3], stoi(tokens[0])));
	}

	
	auto rng = default_random_engine{};
	//I wonder why I need this?
	std::shuffle(std::begin(list), std::end(list), rng);
	return list;
}

int main()
{
	//vector<ComputerScientist*> list = load("csList.txt");
	//vector<ComputerScientist*> list = load("csListSmall.txt");
	// Uncomment later try the different files out
	//BinarySearchTree<int, ComputerScientist*> tree2;
	//vector<ComputerScientist*> list = load("csListMed.txt");
	//for (int i = 0; i < list.size(); i++)
	//{
	//	tree2.insert(list[i], list[i]->getID());
	//}
	//tree2.printTree();
	
	BinarySearchTree<int, ComputerScientist*> tree;

	tree.insert(new ComputerScientist("Ada", "Lovelace", "Programming", 30), 30);
	//tree.printTree();  // these can be used for debugging
	//system("pause");
	tree.insert(new ComputerScientist("Robert", "Ward", "Education", 50), 50);
	//tree.printTree();
	//system("pause");	
	tree.insert(new ComputerScientist("Edsger", "Dikstra", "Algorithms", 80), 80);
	//tree.printTree();
	//system("pause");
	tree.insert(new ComputerScientist("John", "von Neumann", "Hardware", 45), 45);
	//tree.printTree();
	//system("pause");
	tree.insert(new ComputerScientist("Grace", "Hopper", "Compilers", 40), 40);
	//tree.printTree();
	//system("pause");
	tree.insert(new ComputerScientist("Alan", "Turing", "Cryptogarphy", 60), 60);
	//tree.printTree();
	//system("pause");
	tree.insert(new ComputerScientist("Ken", "Thompson", "OS", 70), 70);
	//tree.printTree();
	//system("pause");
	tree.insert(new ComputerScientist("Dennis", "Ritchie", "Compilers", 55), 55);
	//tree.printTree();
	//system("pause");
	tree.insert(new ComputerScientist("Lonnie", "Heinke", "Education", 53), 53);
	//tree.printTree();
	//system("pause");
	tree.insert(new ComputerScientist("Your", "Name", "Skynet", 51), 51);
	//tree.printTree();
	//system("pause");
	tree.insert(new ComputerScientist("Thing", "One", "Education", 54), 54);
	//tree.printTree();
	//system("pause");
	tree.insert(new ComputerScientist("Thing", "Two", "AI", 52), 52);

	tree.printTree(); // ALSO print the height and balance at each node EX: H2:B-1

	system("pause");
	return 0;
}

//Output
/*
Printing: (Ada Lovelace, id: 30, speciality: Programming)
Height: 0 Balance Factor: 0
Printing: (Grace Hopper, id: 40, speciality: Compilers)
Height: 1 Balance Factor: 0
Printing: (John von Neumann, id: 45, speciality: Hardware)
Height: 0 Balance Factor: 0
Printing: (Robert Ward, id: 50, speciality: Education)
Height: 2 Balance Factor: 0
Printing: (Your Name, id: 51, speciality: Skynet)
Height: 1 Balance Factor: -1
Printing: (Thing Two, id: 52, speciality: AI)
Height: 0 Balance Factor: 0
Printing: (Lonnie Heinke, id: 53, speciality: Education)
Height: 3 Balance Factor: 0
Printing: (Thing One, id: 54, speciality: Education)
Height: 0 Balance Factor: 0
Printing: (Dennis Ritchie, id: 55, speciality: Compilers)
Height: 2 Balance Factor: -1
Printing: (Alan Turing, id: 60, speciality: Cryptogarphy)
Height: 0 Balance Factor: 0
Printing: (Ken Thompson, id: 70, speciality: OS)
Height: 1 Balance Factor: 0
Printing: (Edsger Dikstra, id: 80, speciality: Algorithms)
Height: 0 Balance Factor: 0
Press any key to continue . . .
*/

