/*1680. Concatenation of Consecutive Binary Numbers, Medium
Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

Example 1:
Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1. 

Example 2:
Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.

Example 3:
Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 109 + 7, the result is 505379714.
 

Constraints:
1 <= n <= 105

Solution: We will iterate from 1 to n, and for each number, we will calculate its binary representation and add it into a string. Finally, we will convert the concatenated binary string into a decimal number and return it modulo 10^9 + 7.
time: O(n log n) - The time complexity is O(n log n) because for each number from 1 to n, we need to calculate its binary representation which takes O(log n) time.
space: O(1) - We are using a constant amount of space to store the result and the current number's binary representation.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        long long result = 0;
        int mod = 1e9 + 7;
        int length = 0;

        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) {
                length++;
            }
            result = ((result << length) | i) % mod;
        }
        return result;
    }
};

int main() {
    Solution sol;
    int n = 12; // Example input
    cout << sol.concatenatedBinary(n) << endl; // Output: 505379714
    return 0;
}
