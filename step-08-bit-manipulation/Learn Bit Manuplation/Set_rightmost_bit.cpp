/* Set the rightmost bit
Problem Statement: Given a positive integer n, set the rightmost unset (0) bit
of its binary representation to 1 and return the resulting integer.
If all bits are already set, return the number as it is.

Examples
Example 1:
Input: n = 10 (binary: 1010)
Output: 11 (binary: 1011)

Example 2:
Input: n = 7 (binary: 111)
Output: 7

Time: O(log n)
Space: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int SetRightmostBit(int n) {
        int temp = n;
        int i = 0;

        while (temp > 0) {
            if ((n & (1 << i)) == 0) {
                return n | (1 << i);
            }
            temp >>= 1;
            i++;
        }
        return n;
    }
};

int main() {
    Solution sol;
    cout << sol.SetRightmostBit(10) << endl; // 11
    cout << sol.SetRightmostBit(7) << endl;  // 7
    return 0;
}