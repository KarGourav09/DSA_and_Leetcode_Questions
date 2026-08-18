/*32. Longest Valid Parentheses, Hard
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0

Constraints:
0 <= s.length <= 3 * 104
s[i] is '(', or ')'.

Solution: We can solve this problem using a stack to keep track of the indices of the characters in the string. We will iterate through the string and for each character, we will perform the following steps:
1. If the character is '(', we will push its index onto the stack.
2. If the character is ')', we will check if the stack is not empty. If it is not empty, we will pop the top index from the stack and calculate the length of the valid substring by subtracting the current index from the index at the new top of the stack (or -1 if the stack is empty). We will keep track of the maximum length found during this process.

time complexity: O(n), where n is the length of the input string. We are iterating through the string once and performing constant time operations for each character.
space complexity: O(n), where n is the length of the input string. In the worst case, we may need to store all indices in the stack.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(-1); // Initialize stack with -1 to handle edge case for valid substring
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    max_len = max(max_len, i - st.top());
                }
            }
        }
        return max_len;
    }
};

int main() {
    Solution solution;
    string s = ")()())";
    cout << "Longest valid parentheses length: " << solution.longestValidParentheses(s) << endl; // Output: 4
    return 0;
}