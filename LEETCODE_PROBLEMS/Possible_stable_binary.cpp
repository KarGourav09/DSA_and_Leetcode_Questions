/*3129. Find All Possible Stable Binary Arrays I, Medium
You are given 3 positive integers num_zeros, num_ones, and limit.

A binary array arr is called stable if:

The number of occurrences of 0 in arr is exactly num_zeros.
The number of occurrences of 1 in arr is exactly num_ones.
Each subarray of arr with a size greater than limit must contain at least one occurrence of both 0 and 1.
Return an integer denoting the total number of stable binary arrays.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: zero = 1, one = 1, limit = 2

Output: 2

Explanation:

The two possible stable binary arrays are [1,0] and [0,1], as both arrays have a single 0 and a single 1, and no subarray has a length greater than 2.

Example 2:

Input: zero = 1, one = 2, limit = 1

Output: 1

Explanation:

The only possible stable binary array is [1,0,1].

Note that the binary arrays [1,1,0] and [0,1,1] have subarrays of length 2 with identical elements, hence, they are not stable.

Example 3:

Input: zero = 3, one = 3, limit = 2

Output: 14

Explanation:

All the possible stable binary arrays are [0,0,1,0,1,1], [0,0,1,1,0,1], [0,1,0,0,1,1], [0,1,0,1,0,1], [0,1,0,1,1,0], [0,1,1,0,0,1], [0,1,1,0,1,0], [1,0,0,1,0,1], [1,0,0,1,1,0], [1,0,1,0,0,1], [1,0,1,0,1,0], [1,0,1,1,0,0], [1,1,0,0,1,0], and [1,1,0,1,0,0].

 

Constraints:
1 <= zero, one, limit <= 200

Solution: The problem can be solved using dynamic programming. We can define a DP table where dp[i][j] represents the number of stable binary arrays that can be formed with i zeros and j ones. We will iterate through the possible lengths of subarrays and ensure that we do not exceed the limit while maintaining the stability condition.

time: O(zero * one * limit)
space: O(zero * one)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1000000007;
        vector<vector<int>> endWithZero(zero + 1, vector<int>(one + 1, 0));
        vector<vector<int>> endWithOne(zero + 1, vector<int>(one + 1, 0));

        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                if (j == 0) {
                    endWithZero[i][j] = (i <= limit ? 1 : 0);
                    continue;
                }

                if (i == 0) {
                    endWithOne[i][j] = (j <= limit ? 1 : 0);
                    continue;
                }

                long long waysZero = 0;
                for (int used = 1; used <= limit && used <= i; used++) {
                    waysZero += endWithOne[i - used][j];
                }

                long long waysOne = 0;
                for (int used = 1; used <= limit && used <= j; used++) {
                    waysOne += endWithZero[i][j - used];
                }

                endWithZero[i][j] = static_cast<int>(waysZero % MOD);
                endWithOne[i][j] = static_cast<int>(waysOne % MOD);
            }
        }

        return (endWithZero[zero][one] + endWithOne[zero][one]) % MOD;
    }
};

int main() {
    Solution sol;
    int zero = 3, one = 3, limit = 2;
    cout << sol.numberOfStableArrays(zero, one, limit) << endl; // Output: 14
    return 0;
}