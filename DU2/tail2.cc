/** 
 * Petr Zubalik - xzubal04@stud.fit.vutbr.cz
 * tail.c
 * IJC - DU2
 * prelozeno - ...
 */

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <sstream>



int main(int argc, char const *argv[])
{
	using namespace std;
	
	ios::sync_with_stdio(false);
	istream *input= &cin;
	int n = 10;
	string filename;
	ifstream file;

	if (argc == 1 || argc > 4 || argc == 3)
	{
		cerr << "Zadan spatny pocet argumentu!" << endl;
		return -1;
	} else if (argc == 2)
	{
		filename = argv[1];
		file.open(filename, ios::in);
		if (!file.is_open())
		{
			cerr << "Soubor '" << filename << "' se nepodarilo otevrit!" << endl;
			return -1;
		} else {
			input = &file;
		}
	} else if (argc == 4)
	{
		string option_n = argv[1];
		filename = argv[3];
		file.open(filename, ios::in);
		if(!file.is_open())
		{
			cerr << "Soubor '" << filename << "' se nepodarilo otevrit!" << endl;
			return -1;
		} else {
			input = &file;
		}
		if (option_n.compare("-n"))
		{
			cerr << "Program ocekava argument '-n' !" << endl;
			return -1;
		} 
		n = stoi(argv[2]);
		if (n < 0)
		{
			cerr << "Zadany pocet radku nesmi byt mensi nez 0!" << endl;
			return -1;
		}
	}

	queue<string> array;
	string line;

	while(getline(*input, line))
	{
		array.push(line);
		if ((int) array.size() == n+1)
		{
			array.pop();
		}
	}

	for (; !array.empty(); array.pop())
	{
		cout << array.front() << endl;
	}
	
	file.close();

	return 0;
}