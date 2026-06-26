/*205. Isomorphic Strings, Easy
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "f11", t = "b23"

Output: false

Explanation:

The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.

Example 3:

Input: s = "paper", t = "title"

Output: true

 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.

Solution: We can use two hash maps to store the mapping of characters from s to t and from t to s. 
We iterate through the characters of both strings and check if the mapping is consistent. 
If we find any inconsistency, we return false. If we finish iterating through both strings without finding any inconsistencies, we return true.

          Time:  O(n)
          Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map_s[256] = {0};
        char map_t[256] = {0};

        int n = s.length();
        for (int i = 0; i < n; i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (map_s[c1] == 0 && map_t[c2] == 0) {
                map_s[c1] = c2;
                map_t[c2] = c1;
            } else if (map_s[c1] != c2 || map_t[c2] != c1) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;

    vector<pair<string, string>> testCases = {
        {"egg", "add"},
        {"f11", "b23"},
        {"paper", "title"},
        {"foo", "bar"},
        {"ab", "aa"}
    };

    for (const auto &testCase : testCases) {
        string s = testCase.first;
        string t = testCase.second;
        cout << "Input: s = \"" << s << "\", t = \"" << t << "\"" << endl;
        cout << "Output: " << (solution.isIsomorphic(s, t) ? "true" : "false") << endl;
    }
}