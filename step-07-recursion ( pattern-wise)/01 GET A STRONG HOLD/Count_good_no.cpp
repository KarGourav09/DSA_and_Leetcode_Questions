/*1922. Count Good Numbers, Medium
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.


Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303
 

Constraints:

1 <= n <= 1015

Solution: 1. For each index in the digit string, handle two cases: 
   - If the index is even, we can choose from 5 even digits (0, 2, 4, 6, 8).
   - If the index is odd, we can choose from 4 prime digits (2, 3, 5, 7).
        2. Use recursion to calculate the total number of good digit strings of length n, taking care to apply modulo 10^9 + 7 to avoid overflow.
        3. Return the final count of good digit strings of length n.

time: O(log n) for the power function, since we are using exponentiation by squaring.
space: O(1) since we are using a constant amount of space for variables and the recursion stack is not used in this implementation.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long power(long long base, long long exp) {
        long long res = 1;
        const int MOD = 1e9 + 7;
        base %= MOD;
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int countGoodNumbers(long long n) {
        const int MOD = 1e9 + 7;
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long evenChoices = power(5, evenCount);
        long long oddChoices = power(4, oddCount);

        return (evenChoices * oddChoices) % MOD;
    }
};

int main() {
    Solution solution;
    long long n = 4; // Example input
    int result = solution.countGoodNumbers(n);
    cout << "Total good digit strings of length " << n << ": " << result << endl;
    return 0;
}
