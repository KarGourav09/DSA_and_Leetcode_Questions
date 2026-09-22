/*231. Power of Two
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:
Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1

Solution: We can use the Bit manipulation technique to check if a number is a power of two. A number is a power of two if it has exactly one bit set in its binary representation.

time: O(1) since we are performing a constant time operation to check the number of bits set.
space: O(1) since we are using a constant amount of space.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        else if (n == 1) {
            return true;
        }
        else {
            return (n & (n - 1)) == 0;
        }
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    bool result = sol.isPowerOfTwo(n);
    if (result) {
        cout << n << " is a power of two." << endl;
    } else {
        cout << n << " is not a power of two." << endl;
    }

    return 0;
}