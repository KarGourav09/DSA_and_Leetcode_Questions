/*Word Break
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words otherwise return false.

Note : The same word in dictionary can be used multiple times in segmentation.

Example 1
Input : s = "takeuforward" , wordDict = ["take" , "forward" , "you", "u"]
Output : true

Explanation : Return true because "takeuforward" can be segmented as "take" , "u" , "forward".

Example 2
Input : s = "applepineapple" , wordDict = ["apple"]
Output : false

Explanation : Return false because "applepineapple" can be segmented as "apple" , "pine" , "apple" but here we do not have "pine" word in dictionary.

Solution: We can use a single string to keep track of the current path then itrate through the string and check for each substring in the dictionary. If we find a substring in the dictionary, we can recursively check for the remaining substring. We can use a boolean array to keep track of whether a substring can be segmented or not.

time: O(n^3) - In the worst case, we can check all substrings of the string and for each substring, we can check if it is in the dictionary or not.
space: O(n) - We use a boolean array of size n to keep track of whether a substring can be segmented or not.

optimization: We can optimize the solution by using a set to store the dictionary words for faster lookup.

time: O(n^2) - In the worst case, we can check all substrings of the string and for each substring, we can check if it is in the set or not.
space: O(n) - We use a boolean array of size n to keep track of whether a substring can be segmented or not.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true; // Empty string can be segmented

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

int main() {
    Solution solution;
    string s = "takeuforward";
    vector<string> wordDict = {"take", "forward", "you", "u"};
    bool result = solution.wordBreak(s, wordDict);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}