/*999. Prefix to Infix Conversion
You are given a valid arithmetic expression in prefix notation. Your task is to convert it into a fully parenthesized infix expression.

Prefix notation (also known as Polish notation) places the operator before its operands. In contrast, infix notation places the operator between operands.

Your goal is to convert the prefix expression into a valid fully parenthesized infix expression.

Example 1:
Input: expression = "+ab"

Output: "(a+b)"

Example 2:
Input: expression = "*+ab-cd"

Output: "((a+b)*(c-d))"

Algorithm for Prefix to Infix: 

1. Read the Prefix expression in reverse order (from right to left)
2. If the symbol is an operand, then push it onto the Stack
3. If the symbol is an operator, then pop two operands from the Stack 
4. Create a string by concatenating the two operands and the operator between them. 
5. string = (operand1 + operator + operand2) 
6. And push the resultant string back to Stack

Repeat the above steps until the end of Prefix expression.
At the end stack will have only 1 string i.e resultant string

time complexity: O(n), where n is the length of the prefix expression
space complexity: O(n), for the stack used to store operands and intermediate results
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string prefixToInfix(string s) {
        stack<string> st;
        string result = "";
        unordered_map<char, int> precedence = {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'^', 3}
        };
        for(int i = s.length() - 1; i >= 0; i--){
            char c = s[i];
            if(c >= 'a' && c <= 'z' || c >= '0' && c <= '9'){ // Check if the character is an operand
                st.push(string(1, c)); // Push operands (letters and digits) onto the stack
            }
            else{ // Operator encountered
                string operand1 = st.top(); st.pop(); // Pop the first operand
                string operand2 = st.top(); st.pop(); // Pop the second operand
                string newExpr = "(" + operand1 + c + operand2 + ")"; // Create a new expression with parentheses
                st.push(newExpr); // Push the new expression back onto the stack
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;
    string expression = "*+ab-cd"; // Example input expression
    string infix = sol.prefixToInfix(expression);
    cout << "Infix expression: " << infix << endl; // Output: "((a+b)*(c-d))"
    return 0;
}

/*
Using Queue:
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string prefixToInfix(const string& s) {
        queue<string> q;
        string result = "";
        unordered_map<char, int> precedence = {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'^', 3}
        };
        
        for(int i = s.length() - 1; i >= 0; i--){
            char c = s[i];
            if(c >= 'a' && c <= 'z' || c >= '0' && c <= '9'){ // Check if the character is an operand
                q.push(string(1, c)); // Push operands (letters and digits) onto the queue
            }
            else{ // Operator encountered
                string operand1 = q.front(); q.pop(); // Dequeue the first operand
                string operand2 = q.front(); q.pop(); // Dequeue the second operand
                string newExpr = "(" + operand1 + c + operand2 + ")"; // Create a new expression with parentheses
                q.push(newExpr); // Enqueue the new expression back onto the queue
            }
        }
        return q.front();
    }
};
*/
