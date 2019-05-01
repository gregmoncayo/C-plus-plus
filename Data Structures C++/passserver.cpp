//
//  passserver.cpp
//  proj5
//
//  Created by Gregory Moncayo on 4/21/19.
//  Copyright © 2019 Gregory Moncayo. All rights reserved.
//

#include "passserver.h"
#include <unistd.h>

using namespace cop4530;

PassServer:: PassServer(size_t size) : HashTable<string, string>(size){}

PassServer:: ~PassServer()
{
    
}

bool PassServer:: load(const char *filename)
{
    return HashTable<string, string>:: load(filename);
}

bool PassServer:: addUser(std::pair<string,  string> & kv)
{
    pair<string, string> key = make_pair(kv.first, encrypt(kv.second));
    
    return HashTable<string, string>:: insert(key);
}

bool PassServer:: addUser(std::pair<string, string> && kv)
{
    return true;
}

bool PassServer:: removeUser(const string & k)
{
    return HashTable<string, string>:: remove(k);
}

bool changePassword(const pair<string, string> &p, const string & newpassword)
{
    return false;
}

bool PassServer:: find(const string & user) const
{
    return HashTable<string, string>:: contains(user);
}

void PassServer:: dump()
{
    HashTable<string, string>:: dump();
}

size_t PassServer:: size() const
{
    return HashTable<string, string>:: size();
}

bool PassServer:: write_to_file(const char *filename) const
{
    return HashTable<string, string>:: write_to_file(filename);
}

 string PassServer:: encrypt(const string & str)
{
    char salt[] = "$1$########";
    char * password = new char [100];
    strcpy(password, crypt(str.c_str(), salt));
    
    string word = password;
    
    return word;
}

