/*29. Divide Two Integers, Medium
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0

Solution: (Brute force) We can subsequiently subtract the dividend with the divisor and set a counter which increase at every substraction untill the remaining part is less then the divisor or less than equal to 0, we will print the counter.
    time: O(n)
    space: O(1)
          (Optimized) We can use bit manipulation to solve this problem in O(log n) time complexity. We will left shift the divisor until it is less than or equal to the dividend and keep track of the number of shifts. Then we will subtract the shifted divisor from the dividend and add the corresponding power of 2 to the result. We will repeat this process until the dividend is less than the divisor.
    time: O(log n)
    space: O(1)
*/

/*
Brute force solution:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1) return -dividend;

        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long long ans = 0;

        while(dvd >= dvs){
            dvd -= dvs;
            ans++;
        }
        return sign * ans;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1) return -dividend;

        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);

        long long ans = 0;

        while(dvd >= dvs){
            long long temp = dvs, multiple = 1;
            while(dvd >= (temp << 1)){
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            ans += multiple;
        }
        return (dividend > 0) ^ (divisor > 0) ? -ans : ans;
    }
};

int main() {
    Solution sol;
    int dividend = 10, divisor = 3;
    cout << sol.divide(dividend, divisor) << endl; // Output: 3
    return 0;
}