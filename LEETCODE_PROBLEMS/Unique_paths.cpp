/*62. Unique Paths, Medium
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:
1 <= m, n <= 100

Solution: Dynamic Programming, we can use a 2D array to store the number of unique paths to each cell. The number of unique paths to reach a cell (i, j) is the sum of the unique paths to reach the cell directly above it (i-1, j) and the cell directly to the left of it (i, j-1). We initialize the first row and first column with 1s since there is only one way to reach any cell in the first row or first column (by moving right or down respectively). Finally, we return the value in the bottom-right corner of the array which represents the total unique paths to reach that cell.
time complexity: O(m*n)
space complexity: O(m*n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution solution;
    int m = 3, n = 7;
    cout << "Unique paths for grid " << m << "x" << n << ": " << solution.uniquePaths(m, n) << endl;

    m = 3, n = 2;
    cout << "Unique paths for grid " << m << "x" << n << ": " << solution.uniquePaths(m, n) << endl;

    return 0;
}