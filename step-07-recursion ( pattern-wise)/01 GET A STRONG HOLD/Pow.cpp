/*50. Pow(x, n), Medium
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104

Solution: we can implement a recursive loop which will calculate the power of x to n by multiplying x with itself n times. We can also use the property of exponents to reduce the number of multiplications by using the fact that x^n = (x^(n/2))^2 if n is even, and x^n = x * (x^(n-1)) if n is odd. This will reduce the time complexity to O(log n).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(n < 0 && n != INT_MIN) {
            x = 1 / x;
            n = -n;
        }
        if(n % 2 == 0) {
            return myPow(x * x, n / 2);
        } else {
            return x * myPow(x, n - 1);
        }
    }
};

int main() {
    Solution sol;
    double x = 2.00000;
    int n = 10;
    cout << sol.myPow(x, n) << endl; // Output: 1024.00000
    return 0;
}