//
//  Bet.h
//  proj4
//
//  Created by Gregory Moncayo on 3/16/19.
//  Copyright © 2019 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

class BET
{
    public:
        BET();
        ~BET();
        BET(const string postfix);
        BET(const BET &);
        bool buildFromPostfix(const string postfix);
        const BET & operator= (const BET &);
        void printInfixExpression();
        void printPostfixExpression();
        bool empty();
        size_t size();
        size_t leaf_nodes();
        
    private:
        struct BinaryNode
        {
            string element;
            BinaryNode *left;
            BinaryNode *right;
            
            BinaryNode(const string &theElement, BinaryNode *lt, BinaryNode *rt)
            : element{theElement}, left{lt}, right{rt} {}
            BinaryNode(string && theElement, BinaryNode *lt, BinaryNode *rt)
            : element{std::move(theElement)}, left{lt}, right{rt} {}
        };
    
        stack<BinaryNode*> BStack;
        BinaryNode * root;
        bool operand(string value);
        void printInfixExpression(BinaryNode *n);
        void makeEmpty(BinaryNode* &t);
        BinaryNode * clone(BinaryNode *t) const;
        void printPostfixExpression(BinaryNode *n);
        size_t size(BinaryNode *t);
        size_t leaf_nodes(BinaryNode *t);
};

#include "bet.hpp"
