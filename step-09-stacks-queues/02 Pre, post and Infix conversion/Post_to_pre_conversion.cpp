/*989. Postfix to Prefix Conversion
You are given a valid postfix expression as a string, where:

Operands are single lowercase English letters ('a' to 'z')
Operators are binary: '+', '-', '*', '/'
The expression contains no spaces and is guaranteed to be valid.
Write a function to convert the postfix expression into a prefix expression, also as a string without spaces.

Example 1:
Input: expression = "ab+"

Output: "+ab"

Explanation: Postfix → Prefix

Example 2:
Input: expression = "abc*+d-"

Output: "-+a*bcd"

Algorithm for Postfix to Prefix: We use a stack to build the prefix expression step by step:
1. Read the Postfix expression from left to right
2. If the symbol is an operand, then push it onto the Stack
3. If the symbol is an operator, then pop two operands from the Stack 
4. Create a string by concatenating the two operands and the operator before them. 
5. string = operator + operand2 + operand1 
6. And push the resultant string back to Stack
7. Repeat the above steps until end of Postfix expression.

time complexity: O(n), where n is the length of the postfix expression
space complexity: O(n), for the stack used to store operands and intermediate results
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string postToPre(string postfix) {
        stack<string> st;
        for(char c : postfix) {
            if(isalpha(c)) {
                st.push(string(1, c));
            } else {
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                string temp = c + op1 + op2;
                st.push(temp);
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;
    std::cout << "Postfix to Prefix Conversion" << std::endl;

    string expression1 = "ab+";
    cout << "Prefix of " << expression1 << " is: " << sol.postToPre(expression1) << endl; // Output: "+ab"

    string expression2 = "abc*+d-";
    cout << "Prefix of " << expression2 << " is: " << sol.postToPre(expression2) << endl; // Output: "-+a*bcd"
    return 0;
}
