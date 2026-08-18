/*3546. Equal Sum Grid Partition I, Medium
You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

Each of the two resulting sections formed by the cut is non-empty.
The sum of the elements in both sections is equal.
Return true if such a partition exists; otherwise return false.

 

Example 1:
Input: grid = [[1,4],[2,3]]
Output: true
Explanation:
A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.

Example 2:
Input: grid = [[1,3],[2,4]]
Output: false
Explanation:
No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.

Constraints:
1 <= m == grid.length <= 105
1 <= n == grid[i].length <= 105
2 <= m * n <= 105
1 <= grid[i][j] <= 105

Solution: We can solve this problem by calculating the total sum of the grid and then checking if we can find a horizontal or vertical cut that divides the grid into two sections with equal sums.

time: O(m * n) - We need to traverse the entire grid to calculate the total sum and then check for possible cuts.
space: O(1) - We only use a few variables to store sums and indices, so the space complexity is constant.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        long long totalSum = 0;

        for (const auto& row : grid) {
            for (int num : row) {
                totalSum += num;
            }
        }

        if (totalSum % 2 != 0) {
            return false;
        }

        long long targetSum = totalSum / 2;
        long long prefixSum = 0;

        // Check horizontal cuts: sum of top k rows equals target.
        for (int i = 0; i < rows; i++) {
            long long rowSum = 0;
            for (int j = 0; j < cols; j++) {
                rowSum += grid[i][j];
            }
            prefixSum += rowSum;
            if (prefixSum == targetSum && i < rows - 1) {
                return true;
            }
        }

        // Check vertical cuts: sum of left k columns equals target.
        vector<long long> colSums(cols, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                colSums[j] += grid[i][j];
            }
        }

        prefixSum = 0;
        for (int j = 0; j < cols; j++) {
            prefixSum += colSums[j];
            if (prefixSum == targetSum && j < cols - 1) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid1 = {{1, 4}, {2, 3}};
    cout << (solution.canPartitionGrid(grid1) ? "true" : "false") << endl; // Output: true

    vector<vector<int>> grid2 = {{1, 3}, {2, 4}};
    cout << (solution.canPartitionGrid(grid2) ? "true" : "false") << endl; // Output: false

    vector<vector<int>> grid3 = {{14742, 71685, 59237, 27190}};
    cout << (solution.canPartitionGrid(grid3) ? "true" : "false") << endl; // Output: true

    return 0;
}
