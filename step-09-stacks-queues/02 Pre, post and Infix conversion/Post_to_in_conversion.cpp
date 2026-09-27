/*987. Postfix to Infix Conversion
You are given a valid postfix expression as a string, where:

Operands are single lowercase English letters ('a' to 'z')
Operators are binary: '+', '-', '*', '/'
The expression contains no spaces and is guaranteed to be syntactically valid.

Write a function to convert the given postfix expression into a valid infix expression.

Use parentheses to clearly represent the evaluation order of the expression.

Example 1:
Input: "ab+"

Output: "(a+b)"

Explanation:

 postfix : a b +
 infix  : (a + b)
Example 2:
Input: "abc*+"

Output: "(a+(b*c))"

Approach: Using Recursion
1. Start traversing the postfix expression from right to left.
2. If the character is an operand, return it.
3. If it is an operator, recursively get the right and left operands.
4. Combine them as (left operator right).
5. Return the final infix expression.

time complexity: O(n), where n is the length of the postfix expression
space complexity: O(n), for the recursion stack used to store operands and intermediate results
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string postToInfix(string postExp) {
        stack<string> st;
        for(char c : postExp){
            if(isalpha(c)){
                st.push(string(1, c));
            } else {
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                string temp = "(" + op1 + c + op2 + ")";
                st.push(temp);
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;
    std::cout << "Postfix to Infix Conversion" << std::endl;
    string expression1 = "ab+";
    cout << "Infix of " << expression1 << " is: " << sol.postToInfix(expression1) << endl; // Output: "(a+b)"

    string expression2 = "abc*+";
    cout << "Infix of " << expression2 << " is: " << sol.postToInfix(expression2) << endl; // Output: "(a+(b*c))"
    return 0;
}

/*
Using queue:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string postToInfix(string postExp) {
        queue<string> q;
        for(char c : postExp){
            if(isalpha(c)){
                q.push(string(1, c));
            } else {
                string op2 = q.back(); q.pop();
                string op1 = q.back(); q.pop();
                string temp = "(" + op1 + c + op2 + ")";
                q.push(temp);
            }
        }
        return q.back();
    }
};
*/