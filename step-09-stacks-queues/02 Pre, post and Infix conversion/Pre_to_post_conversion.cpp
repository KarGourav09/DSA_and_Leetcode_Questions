/*1003. Prefix to Postfix Conversion
You are given a valid prefix expression consisting of binary operators and single-character operands. Your task is to convert it into a valid postfix expression.

Prefix (Polish) notation places the operator before operands.

Postfix (Reverse Polish) notation places the operator after operands.

Example 1:
Input: expression = "+ab"

Output: "ab+"

Example 2:
Input: expression = "*+ab-cd"

Output: "ab+cd-*"

Approach: 
1. Traverse the prefix expression from right to left
2. If the symbol is an operand, push it onto the stack
3. If the symbol is an operator, pop two operands from the stack, form a postfix string: operand1 + operand2 + operator and push the result back onto the stack
4. Continue until the entire expression is processed
5. The remaining element in the stack is the postfix expression

time complexity: O(n), where n is the length of the prefix expression
space complexity: O(n), for the stack used to store operands and intermediate results
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string prefixToPostfix(const string& s) {
        stack<string> st;
        for(int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];
            if(isalpha(c)) {
                st.push(string(1, c));
            } else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string temp = op1 + op2 + c;
                st.push(temp);
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;
    string expression1 = "*-a/bc-/akl";
    cout << "Postfix of " << expression1 << " is: " << sol.prefixToPostfix(expression1) << endl; // Output: "abc/-ak/l-*"

    string expression2 = "*+ab-cd";
    cout << "Postfix of " << expression2 << " is: " << sol.prefixToPostfix(expression2) << endl; // Output: "ab+cd-*"
    return 0;
}

/*
Using queue:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string prefixToPostfix(const string& s) {
        queue<string> q;
        for(int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];
            if(isalpha(c)) {
                q.push(string(1, c));
            } else {
                string op1 = q.front(); q.pop();
                string op2 = q.front(); q.pop();
                string temp = op1 + op2 + c;
                q.push(temp);
            }
        }
        return q.front();
    }
};
*/