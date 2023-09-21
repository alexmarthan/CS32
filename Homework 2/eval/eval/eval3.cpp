#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

int carrano(string infix,string& postfix);
char evaluateExpression(char operand1,char operand2, char operatuh);
void postfixEval(string& postfix, bool& result);

int evaluate(string infix, string& postfix, bool& result){
    
    if (carrano(infix,postfix) == 0){    // check for valid syntax and convert to postfix form
        
        //evaluate the postfix expression
        postfixEval(postfix,result); // result is either true or false
        
        return 0;
    }
    return 1; // if invalid syntax
}

int carrano(string infix,string& postfix){
    
    //carrano's code for infix to postfix conversion step
    postfix = "";
    stack<char> operatorStack;
    int openParCounter(0), closedParCounter(0); // to keep track of how many parentheses have been opened and closed
    
    if (infix.empty()) return 1; // if empty return 1
    
    string reducedInfix(""); // this will hold our reduced infix (with spaces removed)
    
    for (int i = 0; i < infix.size(); i++){ // algorithm to remove spaces from infix expression
        if (infix.at(i) != ' '){
            reducedInfix+= infix.at(i);
        }
    }
    
    infix = reducedInfix;
    
    for (int i = 0; i < infix.size() ;i++){ // iterating through infix expression
        
        char myChar = infix.at(i);
        
        switch(myChar){
            case 'T':
            case 'F':
                if ( i != infix.size() - 1 && (infix.at(i+1) == 'T' || infix.at(i+1) == 'F' || infix.at(i+1) == '(' || infix.at(i+1) == '!')){ // cannot be followed by T or F or ( or !
                    return 1;
                }
                postfix += myChar; // append to end of postfix
                break;
            case '(':
                openParCounter++;
                if (i != infix.size()-1 && (infix.at(i+1) == ')' || infix.at(i+1) == '&' || infix.at(i+1) == '^')){ // cannot be followed by ), &, ^.
                    return 1;
                }
                if (i == infix.size()-1){ // cant be the last
                    return 1;
                }
                operatorStack.push(myChar); // append to stack
                break;
            case ')':
                closedParCounter++;
                if (i != infix.size()-1 && infix.at(i+1) == '('){ // cannot be followed by (
                    return 1;
                }
                if (i == 0){ // cant be the first
                    return 1;
                }
                while (operatorStack.top() != '('){ // til we reach a opening parenthesis
                    postfix += operatorStack.top(); // append top to postfix
                    operatorStack.pop(); // pop the stack
                }
                operatorStack.pop(); // pop the opening parenthesis
                break;
            case '&':
                
                if (i != infix.size()-1 && (infix.at(i+1) == ')' || infix.at(i+1) == '&' || infix.at(i+1) == '^')){ // cannot be followed by ), &, ^.
                    return 1;
                }
                if (i == infix.size()-1){ // cant be the last
                    return 1;
                }
                
                while (!operatorStack.empty() && operatorStack.top() != '(' && operatorStack.top() != '^'){ // accounting for precedence
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(myChar); // push '&' to stack
                break;
            case '^':
                if (i != infix.size()-1 && (infix.at(i+1) == ')' || infix.at(i+1) == '&' || infix.at(i+1) == '^')){ // cannot be followed by ), &, ^.
                    return 1;
                }
                if (i == infix.size()-1){ // cant be the last
                    return 1;
                }
                
                while (!operatorStack.empty() && operatorStack.top() != '('){
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(myChar);
                break;
            case '!':
                if (i != infix.size()-1 && (infix.at(i+1) == ')' || infix.at(i+1) == '&' || infix.at(i+1) == '^')){ // cannot be followed by ), &, ^.
                    return 1;
                }
                if (i == infix.size()-1){ // cant be the last
                    return 1;
                }
                if (i != infix.size() - 1 && i != 0){
                    if ((infix.at(i+1) == 'F' || infix.at(i+1) == 'T') && (infix.at(i-1) == 'F' || infix.at(i-1) == 'T')){ // cant be both preceded and followed by F or T
                        return 1;
                    }
                }
                operatorStack.push(myChar);
                break;
            case ' ': // should never run
                return 1;
                break;
            default: // if mychar is none of these characters --> there is a mistake
                return 1;
                break;
        }
    }
    if (closedParCounter != openParCounter) return 1; //check for non matching opening and closing parentheses
    
    while (!operatorStack.empty()){
        postfix += operatorStack.top();
        operatorStack.pop();
    }
    return 0;
}

char evaluateExpression(char operand1,char operand2, char operatuh){ // takes in 3 chars, 2 operands and an operator
    
    char result = 'N'; // should never return N

    switch (operatuh){
        case '&':
            if (operand1 == 'T' && operand2 == 'T'){ // is only true if both are true
                result = 'T';
            }
            else result = 'F';
            break;
        case '^': // is only true if both booleans are different from eachother
            if (operand1 == 'T'){
                if (operand2 == 'F'){
                    result = 'T';
                    break;
                }
            }
            if (operand1 == 'F'){
                if (operand2 == 'T'){
                    result = 'T';
                    break;
                }
            }
            result = 'F';
            break;
        case '!': // this case doesn't care about operand1, just switches the value of the second boolean operand
            if (operand2 == 'F'){
                result = 'T';
            }
            if (operand2 == 'T') {
                result = 'F';
            }
            break;
    }
    
    return result;
}

//Evaluation of postfix expression --> figures out if the boolean expression is true or false

void postfixEval(string& postfix, bool& result){
    stack<char> operandStack;
        
    for (int i = 0; i < postfix.size(); i++){
        char myChar = postfix.at(i);
        if (myChar == 'T' || myChar == 'F'){ // if an operand, push it on the operand stack
            operandStack.push(myChar);
        }
        else if (myChar == '!'){ // if '!', switch the value of the boolean operand
            char operand1 = operandStack.top();
            operandStack.pop();
            if (operand1 == 'T'){operand1 = 'F';}
            else operand1 = 'T';
            operandStack.push(operand1); // push !operand1
        }
        else { // if myChar is an operator, save the two last operands in variables and pop them from the stack
            char operand2 = operandStack.top();
            operandStack.pop();
            char operand1 = operandStack.top();
            operandStack.pop();
            operandStack.push(evaluateExpression(operand1,operand2, myChar)); // push the result of the expression on the operand stack
        }
    }
    switch(operandStack.top()){ // this is the final evaluation of postfix expression
        case 'T':
            result = true;
            break;
        case 'F':
            result = false;
            break;
    }
}


int main()
{
    string pf;
    bool answer;
    assert(evaluate("T^ F", pf, answer) == 0);
    assert(pf == "TF^");
    assert(answer);
    assert(evaluate("T^", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("()T", pf, answer) == 1);
    assert(evaluate("T(F^T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("T|F", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    assert(evaluate("(T&(F^F)", pf, answer) == 1);
    assert(evaluate("F  ^  !F & (T&F) ", pf, answer) == 0 &&  pf == "FF!TF&&^"  &&  !answer);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("T", pf, answer) == 0);
    assert(evaluate("(F)", pf, answer) == 0 && answer == false);
    assert(evaluate("T^(F)", pf, answer) == 0 && answer == true);
    assert(evaluate("T ^ !F", pf, answer) == 0 && answer == false);
    assert(evaluate("!(T&F)", pf, answer) == 0 && answer == true);
    assert(evaluate("!T&F", pf, answer) == 0 && answer == false);
    assert(evaluate("T^F&F", pf, answer) == 0 && answer == true);
    assert(evaluate("T&!(F^T&T^F)^!!!(F&T&F)", pf, answer) == 0 && answer == true);
    assert(evaluate("!!!T!!F", pf, answer) == 1);
    

    std::cout << pf << '\n';

    cout << "Passed all tests" << endl;
 }
