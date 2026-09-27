/*963. Infix to Prefix Conversion
Given a valid arithmetic expression in infix notation, return its equivalent prefix (Polish) notation.

The expression can contain:

lowercase letters a–z as operands
the four binary operators + - * /
and round parentheses ( ) that enforce evaluation order
No whitespace appears in the input.
The input is guaranteed to be syntactically correct (parentheses are balanced, every operator has two operands, etc.).

Example 1:
Input: "(a+b)*c"

Output: "*+abc"

Explanation:

Infix  : (a + b) * c

Prefix : * + a b c

Example 2:
Input: "a+b*c"

Output: "+a*bc"

Explanation:

Infix : a + (b * c)

Prefix : + a * b c

Approach: (using stack) The plan here is to scan the infix expression from right to left and use a stack to keep track of operators and parentheses. The output will be built as we process each character in the input expression. If we encounter an operand, we add it directly to the output. If we encounter an operator, we pop operators from the stack to the output until we find an operator of lower precedence or a right parenthesis. We then push the current operator onto the stack. When we encounter a left parenthesis, we pop from the stack to the output until we find a right parenthesis.
          (using queue) We can also use a queue to store the output in the order we encounter operands and operators, ensuring that the final prefix expression is constructed correctly.

time complexity: O(n), where n is the length of the infix expression
space complexity: O(n), for the stack used to store operators and parentheses
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string infixToPrefix(const string& s) {
        stack<char> st;
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
                result += c; // Append operands (letters and digits) directly to the result
            }
            else if(c == ')'){
                st.push(c); // Push ')' onto the stack
            }
            else if(c == '('){
                while(!st.empty() && st.top() != ')'){
                    result += st.top(); // Pop from stack to result until ')' is found
                    st.pop();
                }
                st.pop(); // Pop the ')' from the stack
            }
            else{ // Operator encountered
                while(!st.empty() && precedence[st.top()] > precedence[c]){
                    result += st.top(); // Pop operators of higher precedence
                    st.pop();
                }
                st.push(c); // Push the current operator onto the stack
            }
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    string expression = "(a+b)*c"; // Example input expression
    string prefix = sol.infixToPrefix(expression);
    cout << "Prefix expression: " << prefix << endl; // Output: "*+abc"
    return 0;
}

/*
Using Queue:
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string infixToPrefix(const string& s) {
        queue<char> q;
        stack<char> st;
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
                q.push(c); // Enqueue operands (letters and digits) directly to the queue
            }
            else if(c == ')'){
                st.push(c); // Push ')' onto the stack
            }
            else if(c == '('){
                while(!st.empty() && st.top() != ')'){
                    q.push(st.top()); // Enqueue from stack to queue until ')' is found
                    st.pop();
                }
                st.pop(); // Pop the ')' from the stack
            }
            else{ // Operator encountered
                while(!st.empty() && precedence[st.top()] > precedence[c]){
                    q.push(st.top()); // Enqueue operators of higher precedence
                    st.pop();
                }
                st.push(c); // Push the current operator onto the stack
            }
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        string result = "";
        while(!q.empty()){
            result += q.front();
            q.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
*/