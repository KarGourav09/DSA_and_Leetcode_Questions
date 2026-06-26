/*1781. Sum of Beauty of All Substrings, Medium
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.



Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17


Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.

Solution:
    1. Iterate through all possible substrings of the input string s but to make it more efficient, we canstart it from center and expand outwards to get all possible substrings.
    2. For each substring, calculate the frequency of each character using an unordered_map.

          Time:  O(n^2)
          Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int beautySum(string s)
    {
        int totalBeauty = 0;
        int n = s.length();
        int start = 0, end = 0;
        while (start < n)
        {
            end = start;
            int freq[26] = {0};
            while (end < n)
            {
                freq[s[end] - 'a']++;

                int maxFreq = 0;
                int minFreq = INT_MAX;
                for (int i = 0; i < 26; i++)
                {
                    if (freq[i] > 0)
                    {
                        maxFreq = max(maxFreq, freq[i]);
                        minFreq = min(minFreq, freq[i]);
                    }
                }

                totalBeauty += (maxFreq - minFreq);
                end++;
            }
            start++;
        }
        return totalBeauty;
    }
};

int main()
{
    Solution solution;
    string s1 = "aabcb";
    cout << "Beauty sum of \"" << s1 << "\": " << solution.beautySum(s1) << endl; // Output: 5

    string s2 = "aabcbaa";
    cout << "Beauty sum of \"" << s2 << "\": " << solution.beautySum(s2) << endl; // Output: 17

    return 0;
}