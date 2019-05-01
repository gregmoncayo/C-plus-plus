//
//  main.cpp
//  proj1.cpp
//
//  Created by Gregory Moncayo on 1/11/19.
//  Copyright © 2019 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <iterator>
#include <cctype>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[])
{
    map<string, int> map1; // Empty Map for string word
    map<string, int> map2; // Empty Map for String digit
    map<char, int> map3; // Empty Map for Character
    
    string word = "";   // Empty string
    string str = "";
    int count = 1;      // variable for key value
    
    char answer = NULL;             // empty character for input
    
    int strCount = 0;       // counter for map2
    int DigitCount = 0;     // counter for map1
    int CharacterCount = 0; // counter for map3
    
    cout << "Enter a sentence: ";
    
    while (answer != '\n')
    {
        answer = cin.get();

        map3.insert(pair<char, int>(answer, count));
        map3[answer]++;
        
        if (isdigit(answer))
        {
            word = word + answer;
            
            if (isalpha(cin.peek()) || isspace(cin.peek()) || ispunct(cin.peek()) || cin.eof())
            {
                if (map2.count(word) == 0)
                {
                    map2.insert(pair<string, int>(word, count));
                    DigitCount = DigitCount + 1;
                }
                
                else
                {
                    map2[word]++;
                }
                
                word = "";
            }
        }
        
        else if (isalpha(answer))
        {
            
            str = str + answer;
            
            if (isdigit(cin.peek()) || isspace(cin.peek()) || ispunct(cin.peek()) || cin.eof())
            {
                CharacterCount = CharacterCount + 1;
                for (int x = 0; x < sizeof(str); x++)
                {
                    str[x] = tolower(str[x]);
                }
                
                if (map1.count(str) == 0)
                {
                    map1.insert(pair<string, int>(str, count));
                    strCount = strCount + 1;
                }
                
                else
                {
                    map1[str]++;
                }
                
                str = "";
            }
        }
    }
    
    // Displays results for character map

    cout << "Total " << CharacterCount << " different characters, " << CharacterCount << " most used characters: " << endl;
    
    map<char,int> :: reverse_iterator it;
    map<char, int> :: iterator it5;
    
     auto x = std::max_element(map3.begin(), map3.end(),
     [](const pair<int, int>& p1, const pair<int, int>& p2) {
     return p1.second < p2.second; });
     
     for (it5 = map3.begin(); it5!=map3.end(); it5++)
     {
    // cout << "x: " << x->first << "," << x->second-1 << endl;
     
     x = std::max_element(map3.begin(), map3.end(),
     [](const pair<int, int>& p1, const pair<int, int>& p2) {
     return p1.second < p2.second; });
     }
    
    int i = 0;
    for (it=map3.rbegin(); it!=map3.rend(); it++)
    {
        if (it->second > it5->second)
            cout << "No. " << i << ": " << (*it).first << "\t\t" << (*it).second-1 << endl;
        i++;
    }
    
    // Display results for an string word map

    cout << endl;
    cout << "Total " << strCount << " different words, " << strCount << " most used words:" << endl;
    int k = 0;
    map<string,int> :: iterator itr;
    map<string, int> :: reverse_iterator rev;
    
    for (itr=map1.begin() ; itr!=map1.end() ; itr++)
    {
        cout << "No. " << k << ": " << (*itr).first << "\t\t" << (*itr).second << endl;
        k++;
    }
    
    // Display results for string int map
    cout << endl;
    cout << "Total " << DigitCount << " different numbers, " << DigitCount << " most used numbers:" <<  endl;
    int j = 0;
    map<string,int> :: iterator last;
    map<string, int> :: reverse_iterator rat;
    for (rat=map2.rbegin(); rat!=map2.rend(); rat++)
    {
        cout << "No. " << j << ": " << (*rat).first << "\t\t" << (*rat).second << endl;
        j++;
    }
 
    return 0;
}
