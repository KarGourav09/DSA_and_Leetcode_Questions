/*
Count the number of set bits

Problem Statement: Given an integer n, return the number of set bits (1s) in its binary representation.
Can you solve it in O(log n) time complexity?

Examples
Example 1:
Input: 
n = 5
Output:
 2
Explanation: 
The binary representation of 5 is 101, which has 2 set bits.

Example 2:
Input: 
n = 15
Output: 
4
Explanation: 
The binary representation of 15 is 1111, which has 4 set bits.

Solution: We can solve this Question using Bit Manipulation.

time: O(log n)
space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int NumOfSetBinary(int n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1); // & check if the nth place and 1 is set then increase by 1 else by 0
            n >>= 1; // shifts 1 step left
        }
        return count;
    }
};

int main() {
    Solution sol;
    int n = 15;
    cout << sol.NumOfSetBinary(n) << endl;
    return 0;
}