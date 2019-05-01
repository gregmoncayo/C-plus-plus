//
//  hashtable.h
//  proj5
//
//  Created by Gregory Moncayo on 4/15/19.
//  Copyright © 2019 Gregory Moncayo. All rights reserved.
//
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstring>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// max_prime is used by the helpful functions provided
// to you.
static const unsigned int max_prime = 1301081;
// the default_capacity is used if the initial capacity
// of the underlying vector of the hash table is zero.
static const unsigned int default_capacity = 11;


namespace cop4530
{
    template <class K, class V>
    class HashTable
    {
        public:
            HashTable(size_t size = 101);
            ~HashTable();
            bool contains(const K & k) const;
            bool match(const std::pair<K, V> &kv) const;
            bool insert(const std::pair<K, V> & kv);
            bool insert (std::pair<K,  V> && kv);
            bool remove(const K & k);
            void clear();
            bool load(const char * filename);
            void dump() const;
            size_t size() const;
            bool write_to_file(const char *filename) const;
        
        private:
            vector<list<pair<K,V>>> Lis;
            size_t currentsize;
        
            void makeEmpty();
            void rehash();
            size_t myhash(const K &k) const;
            unsigned long prime_below (unsigned long);
            void setPrimes(vector<unsigned long>&);
    };
#include "hashtable.hpp"
}
#endif
/* hashtable_h */
