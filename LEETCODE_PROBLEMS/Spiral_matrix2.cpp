/*59. Spiral Matrix II, Medium
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]
 
Constraints:
1 <= n <= 20

Solution: We can solve this problem by simulating the process of filling the matrix in a spiral order. We will maintain four boundaries (top, bottom, left, right) to keep track of the current layer of the spiral we are filling. We will fill the matrix in four steps: from left to right, from top to bottom, from right to left, and from bottom to top. After completing one layer, we will move the boundaries inward and repeat the process until we fill the entire matrix.
time: O(n^2), where n is the size of the matrix. We need to fill n^2 elements in the matrix, and each element is filled in constant time.
space: O(n^2), as we are using a 2D vector to store the result matrix, which requires space proportional to the number of elements in the matrix.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {
            // Fill from left to right
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num++;
            }
            top++;

            // Fill from top to bottom
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num++;
            }
            right--;

            // Fill from right to left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = num++;
                }
                bottom--;
            }

            // Fill from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }

        return matrix;
    }
};

int main() {
    Solution solution;
    int n1 = 3;
    vector<vector<int>> result1 = solution.generateMatrix(n1);
    cout << "Spiral Matrix for n = " << n1 << ":\n";
    for (const auto& row : result1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    int n2 = 1;
    vector<vector<int>> result2 = solution.generateMatrix(n2);
    cout << "Spiral Matrix for n = " << n2 << ":\n";
    for (const auto& row : result2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}