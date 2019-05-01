//
//  Bet.hpp
//  proj4
//
//  Created by Gregory Moncayo on 3/16/19.
//  Copyright © 2019 Gregory Moncayo. All rights reserved.
//


// Constructor
BET:: BET(): root{nullptr}
{
    
}


// Destructor
BET:: ~BET()
{
    if(!empty())
    {
        makeEmpty(root);
    }
    
    if(root != nullptr)
    {
        delete root;
    }
}

// one-parameter constructor, where parameter "postfix" is string containing a postfix expression. The tree should be built based on the postfix expression. Tokens in the postfix expression are separated by space.
BET:: BET(const string postfix) : root{nullptr}
{
    buildFromPostfix(postfix);
}

// copy constructor.
BET:: BET(const BET & b) : root{nullptr}
{
    while(!BStack.empty())
    {
        BStack.pop();
    }
    
    root = clone(b.root);
    
    BStack.push(root);
}

// parameter "postfix" is string containing a postfix expression. The tree should be built based on the postfix expression. Tokens in the postfix expression are separated by space. If the tree contains nodes before the function is called, you need to first delete the existing nodes. flagurn true if the new tree is built successfully. flagurn false if an error is encountered.

bool BET:: buildFromPostfix(const string postfix)
{
    bool flag = true;
    string t;
    auto itr = postfix.begin();
    
    if(!empty())
    {
        makeEmpty(root);
        
        while(!BStack.empty())
        {
            BStack.pop();
        }
    }

do
    {
        t = t + *itr;
        
        if(*itr == ' ' || itr == (postfix.end()- 1))
        {
        
            if(*itr == ' ')
            {
                t.pop_back();
            }
            
            if(operand(t))
            {
                    BinaryNode *n = new BinaryNode(t,nullptr,nullptr);
                
                    BStack.push(n);
                
            }
            else if(t == "+" || t == "*" || t == "-" || t == "/")
            {
                BinaryNode *r, *l;
                
                if(!BStack.empty())
                {
                    r = BStack.top();
                    BStack.pop();
                }
                
                else
                {
                    flag = false;
                    break;
                }
                
                if(!BStack.empty())
                {
                    l = BStack.top();
                    BStack.pop();
                }
                
                else
                {
                    flag = false;
                    break;
                }
                
                BinaryNode *op = new BinaryNode(t,l,r);
                
                BStack.push(op);
            }
            t = "";
        }
        ++itr;
    }
    while (itr != postfix.end());
    
    if(!BStack.empty())
    {
        root = BStack.top();
        if(BStack.size() > 1 && operand(root->element))
        {
                    flag = false;
        }
    }
    
    else
    {
        flag = false;
    }
    
    
    if(flag == false)
    {
        cout << "Wrong postfix expression!" << endl;
        
        if(!empty())
        {
            makeEmpty(root);
            
            while(!BStack.empty())
            {
                BStack.pop();
            }
        }
    }
    return flag;
}

// assignment operator
const BET & BET:: operator= (const BET & b)
{
    root = clone(b.root);
    
    while(!BStack.empty())
    {
        BStack.pop();
    }
    
    BStack.push(root);
    
    return *this;
}

// public function that prints the infix expression

void BET:: printInfixExpression()
{
    printInfixExpression(root);
    cout << "\n";
}

// public function that prints the post fix expression

void BET:: printPostfixExpression()
{
    printPostfixExpression(root);
    cout << "\n";
}

// checks whether the tree is empty or not

bool BET:: empty()
{
    return (root == NULL);
}

// public function of size() that returns the size of the tree

size_t BET:: size()
{
    return size(root);
}

// public function of leaf_nodes() that returns the number of leaf under the tree
size_t BET:: leaf_nodes()
{
    return leaf_nodes(root);
}

// private function that makes the tree empty
void BET:: makeEmpty( BinaryNode * & t )
{
    if( t != nullptr )
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
    
}

// private function that prints the infix expression

void BET:: printInfixExpression(BinaryNode *n)
{
    if (n != nullptr)
    {
        if (n != root)
        {
            if (n->element == "+" || n->element == "-" || n->element == "*" || n->element == "/")
            {
                cout << "(";
            }
        }
        
        printInfixExpression(n->left);
        cout << n->element << " ";
        printInfixExpression(n->right);
        
        if (n != root)
        {
            if (n->element == "+" || n->element == "-" || n->element == "*" || n->element == "/")
            {
                cout << ")";
            }
        }
    }
}

// private function that copies the tree

BET:: BinaryNode * BET:: clone(BET:: BinaryNode *t) const
{
    if( t == nullptr )
        return nullptr;
    else
        return new BinaryNode{ t->element, clone(t->left), clone(t->right) };
}

// private function that prints the post fix expression

void BET:: printPostfixExpression(BinaryNode *n)
{
    if(n != nullptr){
        printPostfixExpression(n->left);
        printPostfixExpression(n->right);
        cout << n->element << " ";
    }
}

// private function that counts the size of the tree

size_t BET:: size(BinaryNode *t)
{
    if (t == nullptr)
    {
        return 0;
    }
    
    return (1 + size(t->left) + size(t->right));
}

// private function that counts the leaf nodes

size_t BET:: leaf_nodes(BinaryNode *t)
{
    if (t == nullptr)
    {
        return 0;
    }
    
    if (t->left == nullptr && t->right == nullptr)
        return 1;
    
    return (leaf_nodes(t->left) + leaf_nodes(t->right));
}

// operand function from assignment 3

bool BET:: operand(string value)
{
    for (int i = 0; i < value.size(); i++)
    {
        if(isdigit(value[i]))
        {
            return true;
        }
        
        if (isalpha(value[i]))
        {
            return true;
        }
        
        if (value[i] == '_')
        {
            return true;
        }
    }
    
    return false;
}
