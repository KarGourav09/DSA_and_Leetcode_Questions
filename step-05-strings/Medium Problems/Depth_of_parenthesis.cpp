/*1614. Maximum Nesting Depth of the Parentheses, Easy
Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.


Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"

Output: 3

Explanation:

Digit 8 is inside of 3 nested parentheses in the string.

Example 2:

Input: s = "(1)+((2))+(((3)))"

Output: 3

Explanation:

Digit 3 is inside of 3 nested parentheses in the string.

Example 3:

Input: s = "()(())((()()))"

Output: 3

Constraints:
1 <= s.length <= 100
s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
It is guaranteed that parentheses expression s is a VPS.

Solution: 1.First we will make two pointers, counting the number of opening and closing parentheses.
          2. We will iterate through the string and whenever we encounter an opening parenthesis, we will increment the count of opening parentheses and whenever we encounter a closing parenthesis, we will decrement the count of opening parentheses. 
          3. We will keep track of the maximum count of opening parentheses encountered during the iteration and return that as the result.

          Time:  O(n)
          Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int currentDepth = 0;
        
        for (char c : s) {
            if (c == '(') {
                currentDepth++;
                maxDepth = max(maxDepth, currentDepth);
            } else if (c == ')') {
                currentDepth--;
            }
        }
        
        return maxDepth;
    }
};

int main() {
    Solution solution;
    string s = "(1+(2*3)+((8)/4))+1";
    cout << "Maximum Nesting Depth: " << solution.maxDepth(s) << endl; // Output: 3

    string s2 = "(1)+((2))+(((3)))";
    cout << "Maximum Nesting Depth: " << solution.maxDepth(s2) << endl; // Output: 3

    string s3 = "()(())((()()))";
    cout << "Maximum Nesting Depth: " << solution.maxDepth(s3) << endl; // Output: 3

    return 0;
}