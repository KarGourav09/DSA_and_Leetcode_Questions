/*204. Count Primes, Medium
Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:
0 <= n <= 5 * 106

Solution: We can use the Sieve of Eratosthenes algorithm to efficiently count the number of prime numbers less than n. The algorithm works by iteratively marking the multiples of each prime number starting from 2. The numbers that remain unmarked are prime.
Time Complexity: O(n log log n), where n is the input integer.
Space Complexity: O(n), as we are using a boolean array to keep track of prime numbers.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // Store only odd numbers: index i represents the number 2 * i + 1.
        const int oddCount = n / 2;
        vector<bool> isPrime(oddCount, true);
        isPrime[0] = false; // 1 is not prime.

        for (int p = 3; p * p < n; p += 2) {
            if (isPrime[p / 2]) {
                for (int multiple = p * p; multiple < n; multiple += 2 * p) {
                    isPrime[multiple / 2] = false;
                }
            }
        }

        return count(isPrime.begin(), isPrime.end(), true) + 1; // Include prime 2.
    }
};

int main() {
    Solution sol;
    int n = 10; // Example input
    int result = sol.countPrimes(n);
    cout << result << endl; // Output: 4
    return 0;
}