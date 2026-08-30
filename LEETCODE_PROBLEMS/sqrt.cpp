/*69. Sqrt(x), Easy
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1

Solution: We can use binary search to find the square root of x. The idea is to search for the largest integer m such that m * m <= x. We can initialize our search range from 0 to x, and repeatedly narrow down the range based on the comparison of m * m with x.
time complexity: O(log x)
space complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int low = 1, high = x, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int x = 8;
    cout << "The square root of " << x << " is: " << solution.mySqrt(x) << endl;
    return 0;
}