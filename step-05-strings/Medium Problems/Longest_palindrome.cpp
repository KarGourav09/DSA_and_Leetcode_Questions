/*5. Longest Palindromic Substring, Medium
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

Solution: 1. Define a helper function IsPalindrome(s) to check if a string is a palindrome.
          2. Use two nested loops to generate all possible substrings of s.
          3. For each substring, check if it is a palindrome using the helper function.
          4. Keep track of the longest palindromic substring found so far.
          5. Return the longest palindromic substring after checking all substrings.

        Time:  O(n^2)
        Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            // Case 1: Odd length palindromes (e.g., "aba", center is i)
            int len1 = expandAroundCenter(s, i, i);
            
            // Case 2: Even length palindromes (e.g., "abba", center is between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);

            int len = max(len1, len2);
            
            // If we found a longer palindrome, update our tracking indices
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }

private:
    // Helper function to expand outwards from the center
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Returns the length of the palindrome found
        return right - left - 1;
    }
};

int main() {
    Solution solution;
    string s = "babad";
    cout << solution.longestPalindrome(s) << endl; // Output: "bab" or "aba"

    string s2 = "cbbd";
    cout << solution.longestPalindrome(s2) << endl; // Output: "bb"

    string s3 = "a";
    cout << solution.longestPalindrome(s3) << endl; // Output: "a"

    string s4 = "ac";
    cout << solution.longestPalindrome(s4) << endl; // Output: "a" or "c"

    return 0;
}