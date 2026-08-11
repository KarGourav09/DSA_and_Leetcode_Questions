/*28. Find the Index of the First Occurrence in a String, Easy
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

Solution: Use two pointers, one for haystack and one for needle. Iterate through haystack and check if the substring starting from the current index matches needle. If it does, return the current index. If we reach the end of haystack without finding a match, return -1.

Optimisation: Only check if the first character of the needle matches the current character of haystack, if it does then check for the rest of the characters of needle, if it doesn't then move to the next character of haystack.

time: O(n*m) where n is the length of haystack and m is the length of needle
space: O(1) since we are not using any extra space for the new string,

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        for(int i = 0; i <= n - m; i++) {
            if (haystack[i] == needle[0]) { // Check if the first character matches
                int j;
                for (j = 0; j < m; j++) {
                    if (haystack[i + j] != needle[j]) {
                        break;
                    }
                }
                if (j == m) { // If we have matched the entire needle
                    return i;
                }
            }
        }
        return -1; // If needle is not found in haystack
    }
};

int main() {
    string haystack = "sadbutsad";
    string needle = "sad";
    Solution sol;
    cout << sol.strStr(haystack, needle) << endl; // Output: 0
    return 0;
}