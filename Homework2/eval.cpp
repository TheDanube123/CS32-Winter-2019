//
//  eval.cpp
//  Homework2
//
//  Created by Daniel Miller on 06/02/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

#include "Set.h"  // with ItemType being a type alias for char
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cassert>
using namespace std;

bool topGreaterEqual(char a, char b){
    if (a == b){
        return true;
    }
    if (a == '|' && b == '!'){
        return true;
    }
    else if (a == '|' && b == '&'){
        return true;
    }
    else if (a == '&' && b == '!'){
        return true;
    }
    return false;
}


bool parenthesesChecker(string infix){
    stack<char> parenthesesStack;
    for (int i = 0; i<infix.size(); i++){
        if (infix[i] == ')' && parenthesesStack.empty()){
            return false;
        }
        if (infix[i] == '('){
            parenthesesStack.push(infix[i]);
        }
        if (infix[i] == ')'){
            parenthesesStack.pop();
        }
    }
    if (parenthesesStack.empty()){
        return true;
    }
    return false;
}

bool convertInfixToPostfix(string &infix, string &postfix){
    postfix = "";
    
    for (int i = 0; i<infix.size();i++){                    //get rid of spaces inf infix string
        if (infix[i] == ' '){
            for (int j = i; j < infix.size(); j++){
                if (j!=infix.size()-1){
                    infix[j] = infix[j+1];
                }
                else{
                    infix[j] = ' ';
                }
            }
        }
    }
    
    stack<char> converterStack;
    if (!(parenthesesChecker(infix))){                      //check for parentheses
        return false;
    }
    for (int i = 0; i < infix.size(); i++){
        if (isalpha(infix[i])){                             //check for proper character order
            if (isupper(infix[i])){
                return false;
            }
            if (i != 0){
                if (islower(infix[i-1])){
                    return false;
                }
            }
            postfix += infix[i];                            //append to postfixfor conversion
        }
        else if (infix[i] == '('){
            if (i != 0){                                    //check for proper parentheses order
                if (islower(infix[i-1])){
                    return false;
                }
                if (infix[i-1] == ')'){
                    return false;
                }
            }
            converterStack.push('(');                        //push onto stack
            
        }
        else if (infix[i] == '!' || infix[i] == '&' || infix[i] == '|'){
            if (i==infix.size()-1){                          //cannot end in an operator
                return false;
            }
            if (i!= 0 && infix[i] == '!'){                   //check for ! operator
                if (islower(infix[i-1])){
                    return false;
                }
                if (infix[i-1]==')'){
                    return false;
                }
            }
            if (i!= 0 && infix[i] != '!'){                  //check for operator | and & order
                if (infix[i-1] == '&' || infix[i-1] == '|' || infix[i-1] == '!' || infix[i-1] == '('){
                    return false;
                }
            }
            if (converterStack.empty()){
                converterStack.push(infix[i]);
            }
            else if (!(converterStack.empty())){            //pop operators with greater or less precedence
                while (!(converterStack.empty())){
                    char top = converterStack.top();
                    if (top == '('){
                        break;
                    }
                    else if (!(topGreaterEqual(infix[i],top))){
                        break;
                    }
                    postfix += top;
                    converterStack.pop();
                }
                converterStack.push(infix[i]);
            }
        }
        else if (infix[i] == ')'){                      //last case ( check for order and append operators
            if (i!=0){
                if (islower(infix[i-1]) || infix[i-1] == ')')
                    while (!(converterStack.empty())){
                        char top = converterStack.top();
                        if (top == '('){
                            break;
                        }
                        postfix += top;
                        converterStack.pop();
                    }
                else if (infix[i] != ' '){
                    return false;
                }
            }
        }
    }
    while (!(converterStack.empty())){              //append remaining operators when done with infix string
        char top = converterStack.top();
        if (top == '!' || top == '&' || top == '|'){
            postfix += top;
        }
        converterStack.pop();
    }
    return true;                                    //return true as no errors encountered
}

void postfixEvaluator(const Set& trueValues, const Set& falseValues, string &postfix, bool&result){
    stack<int> evaluator;
    for (int i = 0; i < postfix.size(); i++){
        if (islower(postfix[i])){
            if (trueValues.contains(postfix[i])){
                evaluator.push(1);
            }
            else{
                evaluator.push(0);
            }
        }
        else if (postfix[i] == '&' || postfix[i] == '!' || postfix[i] == '|'){
            int v2 = evaluator.top();
            evaluator.pop();
            if (postfix[i] == '!'){
                int result0 = !v2;
                evaluator.push(result0);
            }
            else{
                int v1 = evaluator.top();
                evaluator.pop();
                if (postfix[i] == '&'){
                    int result2 = v1 & v2;
                    evaluator.push(result2);
                }
                else{
                    int result3 = v1 | v2;
                    evaluator.push(result3);
                }
        }
    }
    
}
    if (evaluator.top() == 1){
        result = true;
    }
    else{
        result = false;
    }
}


int evaluate(string infix, const Set& trueValues, const Set& falseValues, string& postfix, bool& result){
    if (!(convertInfixToPostfix(infix,postfix)) || (infix == "")){
        return 1;
    }
    for (int i = 0; i < infix.size(); i++){
        if (islower(infix[i])){                     //if one value is in both sets
            if (trueValues.contains(infix[i]) && falseValues.contains(infix[i])){
                return 3;
            }                                       // if one value is in neither set
            if (!((trueValues.contains(infix[i]) || falseValues.contains(infix[i])))){
                return 2;
            }
        }
    }
    postfixEvaluator(trueValues, falseValues, postfix, result);
    return 0;
}

int main()
{
    
        string trueChars  = "tywz";
        string falseChars = "fnx";
        Set trues;
        Set falses;
        for (int k = 0; k < trueChars.size(); k++)
            trues.insert(trueChars[k]);
        for (int k = 0; k < falseChars.size(); k++)
            falses.insert(falseChars[k]);
    
        string pf;
        bool answer;
        assert(evaluate("w| f", trues, falses, pf, answer) == 0  &&  pf == "wf|" &&  answer);
        assert(evaluate("y|", trues, falses, pf, answer) == 1);
        assert(evaluate("n t", trues, falses, pf, answer) == 1);
        assert(evaluate("nt", trues, falses, pf, answer) == 1);
        assert(evaluate("()", trues, falses, pf, answer) == 1);
        assert(evaluate("y(n|y)", trues, falses, pf, answer) == 1);
        assert(evaluate("t(&n)", trues, falses, pf, answer) == 1);
        assert(evaluate("(n&(t|7)", trues, falses, pf, answer) == 1);
        assert(evaluate("", trues, falses, pf, answer) == 1);
        assert(evaluate("f  |  !f & (t&n) ", trues, falses, pf, answer) == 0
               &&  pf == "ff!tn&&|"  &&  !answer);
        assert(evaluate(" x  ", trues, falses, pf, answer) == 0  &&  pf == "x"  &&  !answer);
        trues.insert('x');
        assert(evaluate("((x))", trues, falses, pf, answer) == 3);
        falses.erase('x');
        assert(evaluate("((x))", trues, falses, pf, answer) == 0  &&  pf == "x"  &&  answer);
        trues.erase('w');
        assert(evaluate("w| f", trues, falses, pf, answer) == 2);
        falses.insert('w');
        assert(evaluate("w| f", trues, falses, pf, answer) == 0  &&  pf == "wf|" &&  !answer);
        cout << "Passed all tests" << endl;
}

