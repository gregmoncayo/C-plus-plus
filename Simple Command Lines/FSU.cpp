#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    char song[100];
    char ch;
    
    cout << " Enter the fsu fight song: ";
    cin >> song;
    
    cin.get(song, 100, ',');
    //cout << song;
    cin.getline(song, 100, 't');
    //cout << song;
    ch = cin.get();
    cout << ch;
    
    return 0;
}
