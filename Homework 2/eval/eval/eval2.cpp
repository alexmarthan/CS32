//#include <iostream>
//#include <string>
//#include <stack>
//#include <cassert>
//
//using namespace std;
//
//int carrano(string infix,string& postfix);
//char evaluateExpression(char operand1,char operand2, char operatuh);
//void postfixEval(string& postfix, bool& result);
//bool checkValidity(string infix);
//
//int evaluate(string infix, string& postfix, bool& result){
//
//    if (carrano(infix,postfix) == 0){    //convert to postfix form without any issues
//
//        //evaluate the expression (true or false)
//        postfixEval(postfix,result);
//
//        return 0;
//    }
//
//    return 1;
//}
//
//
//
//int carrano(string infix,string& postfix){
//    //carrano's pseudocode for infix to postfix conversion step
//    postfix = "";
//    stack<char> operatorStack;
//    int topPrec(2);
//    int openParCounter(0), closedParCounter(0);
//
//    if (infix.empty()) return 1; // if empty return 1
//    for (int i = 0; i < infix.size() ;i++){
//        char myChar = infix.at(i);
//        int precedence;
//        switch(myChar){
//            case 'T':
//            case 'F':
//                if ( i != infix.size()-1 && (infix.at(i+1) == 'T' || infix.at(i+1) == 'F' || infix.at(i+1) == '(')){ // cannot be followed by T or F or (
//                    return 1;
//                }
//                //if (i != 0 && operatorStack.empty()){} // F ^ T F
//
//                postfix += myChar; // append to end of postfix
//                break;
//            case '(':
//                openParCounter++;
//                if (i != infix.size()-1 && (infix.at(i+1) == ')' || infix.at(i+1) == '&' || infix.at(i+1) == '^')){ // cannot be followed by ), &, ^.
//                    return 1;
//                }
//                if (i == infix.size()-1){ // cant be the last
//                    return 1;
//                }
//                operatorStack.push(myChar);
//                break;
//            case ')':
//                closedParCounter++;
//                if (i != infix.size()-1 && infix.at(i+1) == '('){ // cannot be followed by (
//                    return 1;
//                }
//                if (i == 0){ // cant be the first
//                    return 1;
//                }
//                while (operatorStack.top() != '('){
//                    postfix += operatorStack.top();
//                    operatorStack.pop();
//                }
//                operatorStack.pop();
//                break;
//            case '&':
//
//                if (i != infix.size()-1 && (infix.at(i+1) == ')' || infix.at(i+1) == '&' || infix.at(i+1) == '^')){ // cannot be followed by ), &, ^.
//                    return 1;
//                }
//                if (i == infix.size()-1){ // cant be the last
//                    return 1;
//                }
//                precedence = 0;
//
//                while (!operatorStack.empty() && operatorStack.top() != '(' && precedence <= topPrec){ // must add precedence thang
//                    postfix += operatorStack.top();
//                    operatorStack.pop();
//                    switch(operatorStack.top()){
//                        case '^':
//                            topPrec = 0;
//                            break;
//                        case '&':
//                            topPrec = 1;
//                            break;
//                        case '!':
//                            topPrec = 2;
//                            break;
//                    }
//                }
//                operatorStack.push(myChar);
//                break;
//            case '^':
//                if (i != infix.size()-1 && (infix.at(i+1) == ')' || infix.at(i+1) == '&' || infix.at(i+1) == '^')){ // cannot be followed by ), &, ^.
//                    return 1;
//                }
//                if (i == infix.size()-1){ // cant be the last
//                    return 1;
//                }
//                precedence = 1;
//
//                while (!operatorStack.empty() && operatorStack.top() != '(' && precedence <= topPrec){ // must add precedence thang
//                    postfix += operatorStack.top();
//                    operatorStack.pop();
//                    switch(operatorStack.top()){
//                        case '^':
//                            topPrec = 0;
//                            break;
//                        case '&':
//                            topPrec = 1;
//                            break;
//                        case '!':
//                            topPrec = 2;
//                            break;
//                    }
//                }
//                operatorStack.push(myChar);
//                break;
//            case '!':
//                if (i != infix.size()-1 && (infix.at(i+1) == ')' || infix.at(i+1) == '&' || infix.at(i+1) == '^')){ // cannot be followed by (, &, ^.
//                    return 1;
//                }
//                if (i == infix.size()-1){ // cant be the last
//                    return 1;
//                }
//                if ((infix.at(i+1) == 'F' || infix.at(i+1) == 'T') && (infix.at(i-1) == 'F' || infix.at(i-1) == 'T')){ // cant be both preceded and followed by F or T
//                    return 1;
//                }
//                precedence = 2;
//
//                while (!operatorStack.empty() && operatorStack.top() != '(' && precedence <= topPrec){ // must add precedence thang
//                    postfix += operatorStack.top();
//                    operatorStack.pop();
//                    switch(operatorStack.top()){
//                        case '^':
//                            topPrec = 0;
//                            break;
//                        case '&':
//                            topPrec = 1;
//                            break;
//                        case '!':
//                            topPrec = 2;
//                            break;
//                    }
//                }
//                operatorStack.push(myChar);
//                break;
//            case ' ':
//                break;
//            default:
//                return 1;
//                break;
//        }
//    }
//    if (closedParCounter != openParCounter) return 1; //check for non matching parentheses
//
//    while (!operatorStack.empty()){
//        postfix += operatorStack.top();
//        operatorStack.pop();
//    }
//    return 0;
//}
//
//char evaluateExpression(char operand1,char operand2, char operatuh){
//
//    char result = 'N'; // should never return N
//
//    switch (operatuh){
//        case '&':
//            if (operand1 == 'T' && operand2 == 'T'){
//                result = 'T';
//            }
//            else result = 'F';
//            break;
//        case '^':
//            if (operand1 == 'T' || operand2 == 'T'){
//                result = 'T';
//            }
//            else result = 'F';
//            break;
//        case '!': // this case doesn't care about operand1
//            if (operand2 == 'F'){
//                result = 'T';
//            }
//            if (operand2 == 'T') {
//                result = 'F';
//            }
//            break;
//    }
//
//    return result;
//}
//
////Evaluation of postfix expression --> figures out if the boolean expression is true or false
//
//void postfixEval(string& postfix, bool& result){
//    stack<char> operandStack;
//
//    for (int i = 0; i < postfix.size(); i++){
//        char myChar = postfix.at(i);
//        if (myChar == 'T' || myChar == 'F'){
//            operandStack.push(myChar);
//        }
//        else {
//            char operand2 = operandStack.top();
//            operandStack.pop();
//            char operand1 = operandStack.top();
//            if (myChar!= '!'){
//                operandStack.pop();
//
//            }
//            operandStack.push(evaluateExpression(operand1,operand2, myChar));
//        }
//    }
//    switch(operandStack.top()){ // this is the final evaluation of postfix expression
//        case 'T':
//            result = true;
//            break;
//        case 'F':
//            result = false;
//            break;
//    }
//}
//
//int main()
//{
//    string pf;
//    bool answer;
//    assert(evaluate("T^ F", pf, answer) == 0);
//    assert(pf == "TF^");
//    assert(answer);
//    assert(evaluate("T^", pf, answer) == 1);
//    assert(evaluate("TF", pf, answer) == 1);
//    assert(evaluate("()", pf, answer) == 1);
//    assert(evaluate("()T", pf, answer) == 1);
//    assert(evaluate("T(F^T)", pf, answer) == 1);
//    assert(evaluate("T(&T)", pf, answer) == 1);
//    assert(evaluate("T|F", pf, answer) == 1);
//    assert(evaluate("", pf, answer) == 1);
//    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
//    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
//    assert(evaluate("(T&(F^F)", pf, answer) == 1);
//
//    //assert(evaluate("F  ^  !F & (T&F) ", pf, answer) == 0 &&  pf == "FF!TF&&^"  &&  !answer);
//    //assert(evaluate("F F", pf, answer) == 1);
//
//
//         /*
//     cout << "Passed all tests" << endl;
//     */
// }
