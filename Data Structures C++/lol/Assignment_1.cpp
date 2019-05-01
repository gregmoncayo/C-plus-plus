#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
int main()
{
	map<string, int> numword; //stores string as the key and the value keeps count
	map<char, int> numchar;
	map<string, int>wordint;
	string number = ""; //keeps track of continious numbers
	string word = "";
	bool conword = 0; //counter
	bool conint = 0;
	string words = ""; //sorting
	string numbers = "";
	char present;
	while (cin.get(present)) //collects input
	{
		//cout << '\n';
		//cout.put(present);
		//cout << '\n';
		if (isalpha(present) || ispunct(present) || isspace(present)) //checks 
		{
			if (isalpha(present))
			{
				if (conword == 0) //if the previous input is not a character, it restarts the word string
					word = "";
				if (numchar.count(present) == 0) //checks if the key exists already
				{
					numchar.insert(pair<char, int>(present, 1));
				}
				else
				{
					numchar[present]++;
				}
				word += tolower(present);
				words += tolower(present); //for sorting
				if (conword = 1)
				{
					int d = cin.peek();
					if (isdigit(d) || isspace(d) || ispunct(d) || cin.eof()) //checks the following input to see if it is valid or not
					{
						if (numword.count(word) == 0) {
							numword.insert(pair<string, int>(word, 1));
						}

						else
							numword[word]++;
					}
				}

				conint = 0; //counter
				conword = 1;
			}
			else
			{
				conint = 0;
				conword = 0;
				words += tolower(present);
				if (numchar.count(present) == 0)
				{
					numchar.insert(pair<char, int>(present, 1));
				}
				else
				{
					numchar[present]++;

				}
			}
		}
		else if (isdigit(present))
		{
			string s;
			char conversion;
			if (conint == 0)
				number = "";
			if (numchar.count(static_cast<char>(present)) == 0)
			{
				conversion = static_cast<char>(present);
				numchar.insert(pair<char, int>(conversion, 1));

			}
			else
			{
				//if (numint.count(present) >= 1)
				conversion = static_cast<char>(present); //so it can be stored in the numchar map
				numchar[conversion]++;
			}
			number += conversion; //stores in the map
			numbers += tolower(present); //for sorting

			if (conint = 1)
			{
				int d = cin.peek();
				if (d)
					if (isalpha(d) || isspace(d) || ispunct(d) || cin.eof())
					{
						if (wordint.count(number) == 0)
							wordint.insert(pair<string, int>(number, 1));
						else
							wordint[number]++;
					}

			}
			conint = 1;
			conword = 0;
		}
	}

	cout << "Total ";
	cout << numchar.size();
	cout << " different characters ";
	if (numchar.size() > 10)
		cout << "10 most used characters\n";
	else
		cout << numchar.size() << " most used characters:\n";
	int x = 0;
	int longestwrd = 0; //to get the correct spacing
	for (map<string, int>::iterator  its = numword.begin(); its != numword.end(); ++its)
	{
		int temp = its->first.size();
		if (longestwrd < temp)
		{
			longestwrd = its->first.size();
		}
	}
	for (map<string, int>::iterator  its = wordint.begin(); its != wordint.end(); ++its)
	{
		int temp = its->first.size();
		if (longestwrd < temp)
		{
			longestwrd = its->first.size();
		}
	}
	

	
	for (int i = 0; i < 10; i++) 
	{
		map<char, int>::iterator tracker = numchar.begin();
		if (numchar.empty())
			break;
		for (map<char, int>::iterator it = numchar.begin(); it != numchar.end(); ++it) //checks for the highest size
		{
			if (it->second > tracker->second)
			{
				tracker = it;
			}
			else if (it->second == tracker->second) //if equal, it checks for the minimium ascii value
			{
				if (it->first < tracker->first)
				{
					tracker = it;
				}
			}
		}
		int sum = longestwrd + 5;
		int difference = sum - 1;
		cout << "No. " << x << ": ";
		if (tracker->first == '\n')
			cout << "\\n";
		else if (tracker->first == '\t')
			cout << "\\t";
		else
			cout << tracker->first;

		int original = difference;
		for (int i = 0; i < difference; i++)
		{
			if (tracker->first == '\n') //the character is too character long
			{
				cout << " ";
				difference--;

			}


			else if (tracker->first == '\t')
			{
				cout << " ";
			}

			else{
				difference = original;
				cout << " ";
			}

		}

		cout << tracker->second;
		numchar.erase(tracker); //erases the current max value
		cout << '\n';
		x++;;
	}
	
	cout << "Total ";
	cout << numword.size();
	cout << " different word ";
	if (numword.size() > 10)
		cout << "10 most used words:\n";
	else
		cout << numword.size() << " most used words:\n";
	x = 0;

	for (int i = 0; i < 10; i++) {
		map<string, int>::iterator  tracker = numword.begin();
		if (numword.empty())
			break;
		for (map<string, int>::iterator  it = numword.begin(); it != numword.end(); ++it)
		{
			if (it->second > tracker->second)
			{
				tracker = it;
			}
			else if (it->second == tracker->second)
			{
				size_t found = words.find(it->first);
				int loc;
				int	loc1;
				if (found != string::npos)
				{
					int loc = found;
				}
				found = words.find(tracker->first);
				if (found != string::npos)
				{
					int loc1 = found;
				}
				if (loc1 < loc)
				{
					tracker = it;
				}
				/* (it->first < tracker->first)
				{
					tracker = it;
				}*/
			}
		}
		
		int sum = longestwrd + 5;
		int difference = sum - tracker->first.size();
		cout << "No. " << x << ": " << tracker->first; 
		for (int i = 0; i < difference; i++)
			cout << " ";
		cout<< tracker->second;
		numword.erase(tracker);
		cout << '\n';
		x++;;
	}
	cout << "Total ";
	cout << wordint.size();
	cout << " different word ";
	if (wordint.size() > 10)
		cout << "10 most used numbers:\n";
	else
		cout << wordint.size() << " most used numbers:\n";
	x = 0;

	for (int i = 0; i < 10; i++) {
		map< string, int>::iterator  tracker = wordint.begin();
		if (wordint.empty())
			break;
		for (map<string, int>::iterator  it = wordint.begin(); it != wordint.end(); ++it)
		{
			if (it->second > tracker->second)
			{
				tracker = it;
			}
			else if (it->second == tracker->second)
			{
				if ((it->first.size()) > (tracker->first.size()))
				{
					tracker = it;
				}
				else if ((it->first.size()) == (tracker->first.size()))
				{
					size_t found = words.find(it->first);
					int loc;
					int	loc1;
					if (found != string::npos)
					{
						int loc = found;
					}
					found = words.find(tracker->first);
					if (found != string::npos)
					{
						int loc1 = found;
					}
					if (loc1 > loc)
					{
						tracker = it;
					}
				}
			}
		}
		int sum = longestwrd + 5;
		int difference = sum - tracker->first.size();
		cout << "No. " << x << ": " << tracker->first;
		for (int i = 0; i < difference; i++)
			cout << " ";
		cout<< tracker->second;
		wordint.erase(tracker);
		cout << '\n';
		x++;;
	}
	return 0;
}