//
//  hashtable.hpp
//  proj5
//
//  Created by Gregory Moncayo on 4/15/19.
//  Copyright © 2019 Gregory Moncayo. All rights reserved.
//


// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n
#include "hashtable.h"

template <class K, class V>
HashTable<K, V>:: HashTable(size_t size)
{
    Lis.resize(prime_below(size));
    currentsize = 0;
}

template <class K, class V>
HashTable<K, V>:: ~HashTable()
{
    clear();
}

template <class K, class V>
bool HashTable<K, V>:: contains(const K & k) const
{
    auto & catalog = Lis[myhash(k)];
    //Loop through the chainlinked list to check if value is in the hashtable
    for(auto & thisList : catalog)
        if(thisList.first == k)
            return true;    //Key is in table
    return false;
   // return find(begin(catalog), end(catalog), k) != end(catalog);
}

template <class K, class V>
bool HashTable<K, V>:: match(const std::pair<K, V> &kv) const
{
    auto & itr = Lis[myhash(kv)];
    
    for (auto it = itr.begin(); it != itr.end(); ++it)
    {
        if (it.first == itr.first)
        {
            if (it.second == itr.second)
            {
                return true;
            }
        }
    }
    
    
    return false;
}

template <class K, class V>
bool HashTable<K, V>:: insert(const std::pair<K, V> & kv)
{
    auto & whichList = Lis[myhash(kv.first)];
    if (find(begin(whichList), end(whichList), kv) != end(whichList))
    {
        return false;
    }
    
    whichList.push_back(kv);
    
    //  rehash, see Section 5.5
    if (++currentsize > Lis.size())
    {
        rehash();
    }
    
    return true;
    
}

template <class K, class V>
bool HashTable<K, V>:: insert(std::pair<K, V> && kv)
{
    auto & whichList = Lis[myhash(kv.first)];
    if (find(begin(whichList), end(whichList), kv) != end(whichList))
    {
        return false;
    }
    
    whichList.push_back(kv);
    
    //  rehash, see Section 5.5
    if (++currentsize > Lis.size())
    {
        rehash();
    }
    
    return true;
}

template <class K, class V>
bool HashTable<K, V>:: remove(const K & k)
{
    auto & whichList = Lis[myhash(k)];
    auto itr = find(begin(whichList), end(whichList), k);
    
    if (itr == end(whichList))
    {
        return false;
    }
    
    whichList.erase(itr);
    --currentsize;
    
    return true;
}

template <class K, class V>
void HashTable<K, V>:: clear()
{
    while (!Lis.empty())
    {
        Lis.clear();
    }
}

template <class K, class V>
bool HashTable<K, V>:: load(const char * filename)
{
    //Local variables
    std::ifstream infile;
    infile.open(filename);
    
    //Parse the file
    std::string line;
    while(std::getline(infile,line)){
        std::istringstream iss(line);
        std::string user, pass;
        iss >> user >> pass;    //string stream to deliminator whitespace
        std::pair<std::string, std::string> p = std::make_pair (user,pass);
        insert(p);
    }
    infile.close();
    return true;
}

template <class K, class V>
void HashTable<K, V>:: dump() const
{
    for (auto & x : Lis)
    {
        for (auto & lst : x)
        {
            cout << lst.first << " " << lst.second;
        }
        cout << endl;
    }
/*
    for (auto itr = Lis.begin(); itr != Lis.end(); ++itr)
    {
        for (auto it = Lis.begin(); it != Lis.end(); ++it)
        {
            std:: cout << it.first << " " << it.second;
        }
        cout << endl;
    }*/
}

template <class K, class V>
size_t HashTable<K, V>:: size() const
{
    return currentsize;
}

template <class K, class V>
bool HashTable<K, V>:: write_to_file(const char *filename) const
{
    ofstream ofile;
    
    ofile.open(filename);
    
    if (!ofile)
    {
        cout << "That is not a valid file.  Try again!\n";
        return false;
    }
    
    else
    {
        for (auto & it : Lis)
        {
            for (auto & itz : it)
            {
                ofile << itz.first << " " << itz.second << endl;
            }
        }
    }
}

template <class K, class V>
void HashTable<K, V>:: makeEmpty()
{
    for (auto & index : Lis)
    {
        Lis.clear();
    }
}

template <class K, class V>
void HashTable<K, V>:: rehash()
{
    vector<list<pair<K,V>>> oldLists = Lis;
    
    // create new double-sized, empty table
    Lis.resize(prime_below(2 * Lis.size()));
    for (auto & theList: Lis)
    {
        theList.clear();
    }
    
    // copy table over
    currentsize = 0;
    
    for (auto & thisList : oldLists)
    {
        for (auto & x : thisList)
        {
            insert(std::move(x));
        }
    }
    
}

template <class K, class V>
size_t HashTable<K, V>:: myhash(const K &k) const
{
    static hash<K> hf;
    return hf(k) % Lis.size();
}

template <typename K, typename V>
unsigned long HashTable<K, V>::prime_below (unsigned long n)
{
    if (n > max_prime)
    {
        std::cerr << "** input too large for prime_below()\n";
        return 0;
    }
    if (n == max_prime)
    {
        return max_prime;
    }
    if (n <= 1)
    {
        std::cerr << "** input too small \n";
        return 0;
    }
    
    // now: 2 <= n < max_prime
    std::vector <unsigned long> v (n+1);
    setPrimes(v);
    while (n > 2)
    {
        if (v[n] == 1)
            return n;
        --n;
    }
    
    return 2;
}

//Sets all prime number indexes to 1. Called by method prime_below(n)
template <typename K, typename V>
void HashTable<K, V>::setPrimes(std::vector<unsigned long>& vprimes)
{
    int i = 0;
    int j = 0;
    
    vprimes[0] = 0;
    vprimes[1] = 0;
    int n = vprimes.capacity();
    
    for (i = 2; i < n; ++i)
        vprimes[i] = 1;
    
    for( i = 2; i*i < n; ++i)
    {
        if (vprimes[i] == 1)
            for(j = i + i ; j < n; j += i)
                vprimes[j] = 0;
    }
}

 /* hashtable_h */
