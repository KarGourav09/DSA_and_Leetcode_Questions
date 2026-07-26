/*1536. Minimum Swaps to Arrange a Binary Grid, Medium
Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

A grid is said to be valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

Example 1:
Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3

Example 2:
Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
Output: -1
Explanation: All rows are similar, swaps have no effect on the grid.

Example 3:
Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
Output: 0
 

Constraints:
n == grid.length == grid[i].length
1 <= n <= 200
grid[i][j] is either 0 or 1

Solution: We will focus only on the upper triangle of the grid. for each row, we will count the number of trailing zeros. We will then check if we can arrange the rows such that the first row has at least n-1 trailing zeros, the second row has at least n-2 trailing zeros, and so on. If we can arrange the rows in this way, we will count the number of swaps needed to achieve this arrangement.

time: O(n^2) - The time complexity is O(n^2) because we need to iterate through each row and count the trailing zeros, and then we may need to perform swaps which can take up to O(n) time for each row.
space: O(n) - We are using an additional array to store the count of trailing zeros for each row, which takes O(n) space.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros(n);
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) {
                    count++;
                } else {
                    break;
                }
            }
            trailingZeros[i] = count;
        }

        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            int requiredZeros = n - 1 - i;
            if (trailingZeros[i] >= requiredZeros) {
                continue;
            }
            int j = i + 1;
            while (j < n && trailingZeros[j] < requiredZeros) {
                j++;
            }
            if (j == n) {
                return -1; // No row found with enough trailing zeros
            }
            // Swap rows to bring the row with enough trailing zeros to position i
            while (j > i) {
                swap(trailingZeros[j], trailingZeros[j - 1]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0,0,1},{1,1,0},{1,0,0}}; // Example input
    cout << sol.minSwaps(grid) << endl; // Output: 3
    return 0;
}