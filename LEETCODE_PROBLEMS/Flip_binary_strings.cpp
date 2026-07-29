/*1888. Minimum Number of Flips to Make the Binary String Alternating, Medium
You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
 

Example 1:

Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
Example 2:

Input: s = "010"
Output: 0
Explanation: The string is already alternating.
Example 3:

Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".

Solution: We can solve this problem by considering the two possible alternating patterns: "010101..." and "101010...". For each character in the string, we can count how many flips are needed to convert it to each of these patterns.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string s2 = s + s; // Concatenate the string to itself to handle rotations
        int flips1 = 0, flips2 = 0; // Flips needed for patterns "0101..." and "1010..."
        int minFlips = INT_MAX;

        for (int i = 0; i < s2.size(); ++i) {
            // Check the expected character for both patterns
            char expected1 = (i % 2 == 0) ? '0' : '1'; // Pattern "0101..."
            char expected2 = (i % 2 == 0) ? '1' : '0'; // Pattern "1010..."

            if (s2[i] != expected1) flips1++;
            if (s2[i] != expected2) flips2++;

            // When we have considered a full window of size n
            if (i >= n - 1) {
                minFlips = min(minFlips, min(flips1, flips2));

                // Remove the effect of the character that is sliding out of the window
                if (s2[i - n + 1] != ((i - n + 1) % 2 == 0 ? '0' : '1')) flips1--;
                if (s2[i - n + 1] != ((i - n + 1) % 2 == 0 ? '1' : '0')) flips2--;
            }
        }

        return minFlips;
    }
};

int main() {
    Solution sol;
    string s = "01001001101";
    cout << sol.minFlips(s) << endl; // Output: 2
    return 0;
}