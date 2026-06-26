/*796. Rotate String, Easy
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters

Solution: 1. First we will check if the length of both strings is equal, if not then we can return false.
          2. We will iterate through the string s and for each character, we will check if it is equal to the first character of goal.
          3. If it is equal, then we will perform a left shift on s and check if it is equal to goal.
          4. If it is equal, then we can return true else we can continue the iteration.
          5. If we reach the end of the string without finding any match, then we can return false.

        Time:  O(n^2)
        Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        for(int i = 0; i < s.length(); i++) {
            if (s == goal) {
                return true;
            }
            // Perform a left shift on s
            char firstChar = s[0];
            s.erase(0, 1); // Remove the first character
            s.push_back(firstChar); // Append the first character to the end
        }
        return false;
    }
};

int main() {
    Solution solution;
    string s = "abcde";
    string goal = "cdeab";
    bool result = solution.rotateString(s, goal);
    cout << (result ? "true" : "false") << endl; // Output: true

    s = "abcde";
    goal = "abced";
    result = solution.rotateString(s, goal);
    cout << (result ? "true" : "false") << endl; // Output: false

    return 0;
}