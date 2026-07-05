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

Solution: 1. We can use a recursive approach to solve this problem. We can define a recursive function that takes the current index and the length of the string as parameters. If the current index is equal to the length of the string, we have found a good number and we can return 1. Otherwise, we can check if the current index is even or odd. If it is even, we can iterate through all even digits (0, 2, 4, 6, 8) and call the recursive function for the next index. If it is odd, we can iterate through all prime digits (2, 3, 5, 7) and call the recursive function for the next index. We can keep track of the total count of good numbers and return it at the end.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodNumbers(long long n) {
        if(n == 0) return 1;
        
        long long 
        }
        return result;
    }
};

int main() {
    Solution sol;
    long long n = 4;
    cout << sol.countGoodNumbers(n) << endl; // Output: 400
    return 0;
}