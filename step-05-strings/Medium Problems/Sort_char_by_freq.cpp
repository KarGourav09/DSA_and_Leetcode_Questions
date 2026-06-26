/*451. Sort Characters By Frequency, Medium
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.


Solution:
1. first we will count the frequency of each character in the string using a vector of pairs where each pair contains a character and its frequency.
3. we will sort the vector of pairs in decreasing order based on the frequency of the characters.

          Time:  O(n log n)
          Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    static bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    }


public:
    string frequencySort(string s) {
        vector<pair<char, int>> freqVec;

        for (char c : s) {
            bool found = false;
            for (auto& p : freqVec) {
                if (p.first == c) {
                    p.second++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                freqVec.push_back({c, 1});
            }
        }
        sort(freqVec.begin(), freqVec.end(), cmp);

        string result;
        for (const auto& p : freqVec) {
            result.append(p.second, p.first);
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "tree";
    cout << solution.frequencySort(s) << endl; // Output: "eert" or "eetr"
    return 0;
}