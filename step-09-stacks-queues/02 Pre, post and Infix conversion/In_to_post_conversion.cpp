/*930. Infix to Postfix Conversion
You are given a string expression representing a valid infix mathematical expression. Your task is to convert this expression into its equivalent postfix notation, also known as Reverse Polish Notation (RPN).

The expression may include:

Operands: single lowercase English letters (a to z) or single-digit numbers (0 to 9)
Binary operators: +, -, *, /, ^
Parentheses: ( and ) to indicate grouping and precedence

Operator precedence (from highest to lowest):
^ (exponentiation)
*, / (multiplication and division)
+, - (addition and subtraction)

Associativity:
^ is right-associative
All other operators are left-associative
Parentheses override standard precedence
You must return the corresponding postfix expression as a string.

The result must not contain any spaces or separators between characters.

Example 1:
Input: expression = "a+b*c"

Output: "abc*+"

Explanation:

Multiplication has higher precedence than addition, so b * c is evaluated first, then added to a.

Example 2:
Input: expression = "(a+b)*c"

Output: "ab+c*"

Explanation:

The parentheses ensure that a + b is evaluated before multiplying with c.

Approach: (using stack) The plan here is to scan the infix expression from left to right and use a stack to keep track of operators and parentheses. The output will be built as we process each character in the input expression. If we encounter an operand, we add it directly to the output. If we encounter an operator, we pop operators from the stack to the output until we find an operator of lower precedence or a left parenthesis. We then push the current operator onto the stack. When we encounter a right parenthesis, we pop from the stack to the output until we find a left parenthesis.
          (using queue) We can also use a queue to store the output in the order we encounter operands and operators, ensuring that the final postfix expression is constructed correctly.

time complexity: O(n), where n is the length of the infix expression
space complexity: O(n), for the stack used to store operators and parentheses
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string infixToPostfix(string s) {
        stack<char> st;
        string result = "";
        unordered_map<char, int> precedence = {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'^', 3}
        };

        for(char c : s){
            if(c >= 'a' && c <= 'z' || c >= '0' && c <= '9'){ // Check if the character is an operand
                result += c; // Append operands (letters and digits) directly to the result
            }
            else if(c == '('){
                st.push(c); // Push '(' onto the stack
            }
            else if(c == ')'){
                while(!st.empty() && st.top() != '('){
                    result += st.top(); // Pop from stack to result until '(' is found
                    st.pop();
                }
                st.pop(); // Pop the '(' from the stack
            }
            else{ // Operator encountered
                while(!st.empty() && precedence[st.top()] >= precedence[c]){
                    result += st.top(); // Pop operators of higher or equal precedence
                    st.pop();
                }
                st.push(c); // Push the current operator onto the stack
            }
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result;
    }
};

int main() {
    Solution sol;
    string expression = "a+b*c+d"; // Example input expression
    string postfix = sol.infixToPostfix(expression);
    cout << "Postfix expression: " << postfix << endl; // Output: "abc*+d+"
    return 0;
}

/*
Using Queue:
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string infixToPostfix(string s) {
        queue<char> outputQueue;
        stack<char> operatorStack;
        unordered_map<char, int> precedence = {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'^', 3}
        };

        for(char c : s){
            if(c >= 'a' && c <= 'z' || c >= '0' && c <= '9'){ // Check if the character is an operand
                outputQueue.push(c); // Enqueue operands (letters and digits) directly to the output queue
            }
            else if(c == '('){
                operatorStack.push(c); // Push '(' onto the stack
            }
            else if(c == ')'){
                while(!operatorStack.empty() && operatorStack.top() != '('){
                    outputQueue.push(operatorStack.top()); // Pop from stack to output queue until '(' is found
                    operatorStack.pop();
                }
                operatorStack.pop(); // Pop the '(' from the stack
            }
            else{ // Operator encountered
                while(!operatorStack.empty() && precedence[operatorStack.top()] >= precedence[c]){
                    outputQueue.push(operatorStack.top()); // Pop operators of higher or equal precedence
                    operatorStack.pop();
                }
                operatorStack.push(c); // Push the current operator onto the stack
            }
        }
        while(!operatorStack.empty()){
            outputQueue.push(operatorStack.top());
            operatorStack.pop();
        }

        string result = "";
        while(!outputQueue.empty()){
            result += outputQueue.front();
            outputQueue.pop();
        }
        return result;
    }
};
*/