//
//  main.cpp
//  in2post
//
//  Created by Gregory Moncayo on 3/4/19.
//  Copyright © 2019 Gregory Moncayo. All rights reserved.
//
#include "Stackz.h"
using namespace std;
using namespace cop4530;

vector<string> infix2postfix(const std:: vector<string> &infix);    // infix2postfix function that stores the numbers & the operator symbol
bool operand(string token);                            // operand function that returns true if parameter is a number, character, or underscore
int precedence(string value);                           // returns the highest value of Orders of operations when it comes to operator symbols
void EvaluatePostfix(std::vector<string> exp);          // Evaluates the number according to order of operations
bool isCharacter(string v);                             // returns true if parameter is an alphabetical letter

int main(int argc, const char * argv[])
{
    vector<string> seq;     // vector that stores the strings
    Stack<string> s;        // Stack string
    string str = "\n";      // string variable that stores the sentence which the user enters
    string tmp = "\n";      // temperary variable that stores the sentence which will be copied into the vector
    
    
    // Loop that runs until the end of the string
while (!cin.eof())
    {
        bool flag = false;      // bool variable that stores false if string does not contain a letter
        s.clear();              // clears the stack string
        
        // for user entry
        
        cout << "Enter infix expression (""exit"" to quit): ";
        tmp = " ";
        str=" ";
        
        //  nested while loop that reads the string sentence from user input
        while (getline(cin, str))
        {
            // if user types in exit, exits program
            
            if (str == "exit")
            {
                return 0;
            }
            
            // clears the vector
            seq.clear();
            
            // get one integer sequence
    
            istringstream mystr(str);
            
            // stores the string into a temp
            
            while (mystr >> tmp)
            {
                seq.push_back(tmp);     // pushes the string into the vector
                
            }
            
            // loops through the vector to determine whether the string contains a letter
            
                for (auto itr = seq.begin(); itr != seq.end(); ++itr)
                {
                    if (isCharacter(*itr))
                    {
                        flag = true;
                    }
                }
            
            // if string contains a letter, prints out the letters
            
            if (flag == true)
            {
                cout << " = ";
                infix2postfix(seq);
                cout << endl;
            }
            
            // if string contains no letters, prints out the numbers
            
            else
            {
                cout << "Postfix expression: ";
                infix2postfix(seq);
                cout << endl;
                
                cout << "Postfix evaluation: ";
                EvaluatePostfix(seq);
                cout << endl;
            }
            
        }
    }
    
    
    return 0;
}

// returns true if string contains an operator

bool Operator(string token)
{
    if (token == "+")
    {
        return true;
    }
    
    else if (token == "*")
    {
        return true;
    }
    
    else if (token == "-")
    {
        return true;
    }
    
    else if (token == "/")
    {
        return true;
    }
    
    return false;
}

// returns true if letter is contain within the string

bool isCharacter(string v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (isalpha(v[i]))
        {
            return true;
        }
    }
    
    return false;
}

// returns true if string contains numbers, letters, or underscores

bool operand(string value)
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

// returns highest value of operators by order of operations

int precedence(string value)
{
    if (value == "(" || value == ")")
    {
        return 4;
    }
    
    else if (value == "*" || value == "/")
    {
        return 3;
    }
    
    else if (value == "+" || value == "-")
    {
        return 2;
    }
    
    return -1;
}

// Evaluates the number according to order of operations

void EvaluatePostfix(std::vector<string> exp)
{
    Stack<float> SI;        // stack of floats
    vector<string> vec;     // empty vector
    
    vector<string> myvec = infix2postfix(exp);      // vector that contains elements from postfix expression
    
    string temp = " ";          // temperary string
    double answer = 0;          // variable to store the math from the operations
    
    // use stack of tokens;
    auto itr = myvec.begin();       // iterator that starts at the beginning of the vector
    
    // loops through the vector
    
    while(itr != myvec.end())
    {
        // if slot is a digit, character, or underscore, storewithin the Stack<float>
        
          if (operand(*itr))
          {
              float p = std::stof(*itr);
              SI.push(p);
              // push onto stack
          }

        // iterates through the element and stores data into temperary data & pops until end of the string
        
          else
          {
              float S1 = SI.top();
              SI.pop();
              float S2 = SI.top();
              SI.pop();
              // pop operands for t off stack
              
              // if slot is an operator, stores the math expression into answer
              
              if (Operator(*itr))
              {
                  if (*itr == "+")
                  {
                      answer = S1 + S2;
                  }
                  
                  else if (*itr == "-")
                  {
                      answer = S2 - S1;
                  }
                  
                  else if (*itr == "*")
                  {
                      answer = S1 * S2;
                  }
                  
                  else if (*itr == "/")
                  {
                      if (S1 != 0)
                      {
                          answer =  S2 / S1;
                        //  cout << "Answer: " << answer;
                      }
                  }
                  
                  SI.push(answer);  // pushes the variable to the stack
              }
              
              // evaluate t on these operands
              
              // push result onto stack
              
          }
        
        ++itr;      // increments the iterator
    }
    
    cout << " = " << SI.top() << endl; // prints equal and the top of SI which contains answer
    
    // pops through Stack<float> until it's empty
    
    while (!SI.empty())
    {
        SI.pop();
    }
    
    // return top of stack
}

// infix2postfix function that stores the numbers & the operator symbol

vector<string> infix2postfix(const vector<string> &infix)
{
    Stack<string> s;            // Stack of string
    vector<string> vec;         // empty string vector
    
    for (int I = 0; I < infix.size(); ++I)
    {
        // if parameter contains letters, number, or underscore, print it out/store it
        
        if (operand(infix[I]))
        {
            cout << infix[I] << " ";
            vec.push_back(infix[I]);
        }
        
        // if parameter is an operator, stores it into the vector, deletes the recent stack string, then stores data into the stack
        
        else if (infix[I] == "+" || infix[I] == "-" || infix[I] == "*" || infix[I] == "/" || infix[I] == "(")
        {
            while (!s.empty() && s.top() != "(" && precedence(s.top()) >= precedence(infix[I]))
            {
                vec.push_back(s.top());
                s.pop();
            }
                   s.push(infix[I]);
        }
        
        // if parameter equals closing bracket, stores it into the vector, deletes it
                   
        else if (infix[I] == ")" )
        {
                while (!s.empty() && s.top() != "(")
                {
                    cout << s.top() << " ";
                    vec.push_back(s.top());
                    s.pop();
                }
                       s.pop(); // remove (
        }
        
        // if parameter equals opening bracket, stores it into the stack
        
        else if (infix[I] == "(")
        {
            s.push(infix[I]);
        }
    }
                // while stack isn't empty, stores the elements into the vec then deletes it from the stack
    
                       while (!s.empty())
                       {
                           cout << s.top() << " ";
                           vec.push_back(s.top());
                           s.pop();
                       }
    
    return vec;     // returns the vector
}
