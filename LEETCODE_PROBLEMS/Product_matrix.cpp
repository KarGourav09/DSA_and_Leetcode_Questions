/*2906. Construct Product Matrix
Medium
Given a 0-indexed 2D integer matrix grid of size n * m, we define a 0-indexed 2D matrix p of size n * m as the product matrix of grid if the following condition is met:

Each element p[i][j] is calculated as the product of all elements in grid except for the element grid[i][j]. This product is then taken modulo 12345.
Return the product matrix of grid.

 

Example 1:

Input: grid = [[1,2],[3,4]]
Output: [[24,12],[8,6]]
Explanation: p[0][0] = grid[0][1] * grid[1][0] * grid[1][1] = 2 * 3 * 4 = 24
p[0][1] = grid[0][0] * grid[1][0] * grid[1][1] = 1 * 3 * 4 = 12
p[1][0] = grid[0][0] * grid[0][1] * grid[1][1] = 1 * 2 * 4 = 8
p[1][1] = grid[0][0] * grid[0][1] * grid[1][0] = 1 * 2 * 3 = 6
So the answer is [[24,12],[8,6]].

Example 2:

Input: grid = [[12345],[2],[1]]
Output: [[2],[0],[0]]
Explanation: p[0][0] = grid[0][1] * grid[0][2] = 2 * 1 = 2.
p[0][1] = grid[0][0] * grid[0][2] = 12345 * 1 = 12345. 12345 % 12345 = 0. So p[0][1] = 0.
p[0][2] = grid[0][0] * grid[0][1] = 12345 * 2 = 24690. 24690 % 12345 = 0. So p[0][2] = 0.
So the answer is [[2],[0],[0]].
 

Constraints:

1 <= n == grid.length <= 105
1 <= m == grid[i].length <= 105
2 <= n * m <= 105
1 <= grid[i][j] <= 109

Solution: (Brute Force) loop through each element and calculate the product of all other elements, taking care to use modulo 12345 to avoid overflow. However, this approach has a time complexity of O(n*m*(n*m)), which is inefficient for large matrices.

Optimized Solution: We can calculate the total product of all elements in the grid first, and then for each element p[i][j], we can compute it as total_product / grid[i][j] (taking care to handle division by zero). This reduces the time complexity to O(n*m), which is efficient for large matrices.

time: O(n*m)
space: O(n*m) for the output matrix, but we can optimize space to O(1) if we modify the input matrix in place or use a single variable to store the total product.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int MOD = 12345;

        vector<vector<int>> result(n, vector<int>(m));

        // prefix = product of all elements before current cell (in row-major order)
        long long prefix = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = prefix;
                prefix = (prefix * grid[i][j]) % MOD;
            }
        }

        // suffix = product of all elements after current cell, multiply into result
        long long suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                result[i][j] = (int)((result[i][j] * suffix) % MOD);
                suffix = (suffix * grid[i][j]) % MOD;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 2}, {3, 4}};
    vector<vector<int>> result = sol.constructProductMatrix(grid);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}