//
//  main.cpp
//  Politics as usual
//
//  Created by Gregory Moncayo on 7/13/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cctype>
#include "votes.h"

using namespace std;

ostream& operator<< (ostream& s, const votes& v)
{
    for (int i = 0; i < 26; i++)
    {
        if (isalnum(v.candidate[i]) || isspace(v.candidate[i]))
        s << v.candidate[i];
    }
    
    cout << endl;
    
    for (int i = 0; i < v.numReported; i++)
    {
        s << v.counts[i];
    }
    
    cout << endl;
    
    return s;
}

votes:: votes(const char cand[])
{
    counts = 0;
    numReported = 0;
    int length = strlen(cand);
    
    for (int i = 0; i < length; i++)
    {
        candidate[i] = cand[i];
    }
    
    length = 0;
    
}

votes:: votes(const votes& x)
{
    numReported = x.numReported;
    strcpy(candidate, x.candidate);

    // allocates a new list of arrays
    counts = new int [numReported];
    
    for (int i = 0; i < numReported; i++)
    {
        counts[i] = x.counts[i];
    }
}

votes:: ~votes()
{
    delete [] counts;
}

void votes:: AddPrecinct(int c)
{
    if(c > 0)
    {
        numReported++;
    
    counts = new int [numReported];
    
    for (int i = 0; i < numReported; i++)
    {
        counts[i] = c;
    }
        
    }
}
