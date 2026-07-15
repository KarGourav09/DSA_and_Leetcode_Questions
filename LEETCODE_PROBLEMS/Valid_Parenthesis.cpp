/*20. Valid Parentheses, Easy
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

Solution: Check for the validity of the parentheses using a stack. Iterate through each character in the string, and for every opening bracket, push it onto the stack. For every closing bracket, check if the stack is not empty and if the top of the stack matches the corresponding opening bracket. If it does, pop the top of the stack; otherwise, return false. At the end of the iteration, if the stack is empty, return true; otherwise, return false.

time: O(n), where n is the length of the string s. We traverse the string once, and each push and pop operation on the stack takes O(1) time.
space: O(n), where n is the length of the string s. In the worst case, we may have to store all opening brackets in the stack.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                if ((s[i] == ')' && top != '(') ||
                    (s[i] == '}' && top != '{') ||
                    (s[i] == ']' && top != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;
    string s = "([])";
    cout << (solution.isValid(s) ? "true" : "false") << endl; // Output: true
    return 0;
}