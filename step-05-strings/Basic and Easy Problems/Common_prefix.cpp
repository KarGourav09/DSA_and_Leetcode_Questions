/*14. Longest Common Prefix, Easy
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();

        string prefix = strs[0];

        if (strs.empty())
            return "";

        for (int j = 0; j < prefix.length(); j++)
        {
            char c = prefix[j];
            for (int i = 1; i < strs.size(); i++)
            {
                if (j == strs[i].size() || strs[i][j] != c)
                {
                    return prefix.substr(0, j);
                }
            }
        }
        return prefix;
    }
};

int main()
{
    Solution solution;
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs1) << endl; // Output: "fl"

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs2) << endl; // Output: ""

    vector<string> strs3 = {"ab", "a"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs3) << endl; // Output: "a"
}