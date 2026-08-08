/*10. Regular Expression Matching, Hard
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
Return a boolean indicating whether the matching covers the entire input string (not partial).

 

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
 

Constraints:

1 <= s.length <= 20
1 <= p.length <= 20
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

Solution: We are given 2 strings, one is the input string and the other is the pattern, we will use two pointers to iterate simultaneously through both strings and in the process if found * we will check for the previous character and see if it matches with the current character in the input string, if it does we will move the pointer of the input string to the next character and keep the pattern pointer at the same position, if it doesn't match we will move the pattern pointer to the next character. If we reach the end of both strings at the same time then we return true else false. also for the . we will check if the current character in the input string is equal to the current character in the pattern or if the current character in the pattern is . then we will move both pointers to the next character. If we reach the end of both strings at the same time then we return true else false.

time: O(m * n) where m is the length of the input string and n is the length of the pattern.
space: O(m * n) where m is the length of the input string and n is the length of the pattern.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution solution;
    string s = "aa";
    string p = "a*";
    bool result = solution.isMatch(s, p);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}