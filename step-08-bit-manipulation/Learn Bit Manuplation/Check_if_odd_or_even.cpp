/*Check if a number is odd or not
Problem Statement: Given a non-negative integer n, determine whether it is odd. Return true if the number is odd, otherwise return false. A number is odd if it is not divisible by 2 (i.e., n % 2 != 0).

Examples
Example 1:
Input:
 n = 7
Output:
 true
Explanation:
 7 is not divisible by 2. Hence, it is odd.

Example 2:
Input:
 n = 10
Output:
 false
Explanation:
 10 is divisible by 2. Hence, it is not odd.

Solution: we can use the Bit manipulation technique to check if the 0th bit of the number is set or not. If the 0th bit is set, then the number is odd; otherwise, it is even.

time: O(1) since we are performing a constant time operation to check the 0th bit.
space: O(1) since we are using a constant amount of space.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOdd(int n) {
        return (n & (1 << 0)) != 0;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    bool result = sol.isOdd(n);
    if (result) {
        cout << n << " is odd." << endl;
    } else {
        cout << n << " is even." << endl;
    }

    return 0;
}