/*74. Search a 2D Matrix
Solved
Medium
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
            
        int num_rows = matrix.size();
        int num_cols = matrix[0].size();
        int i = 0;
        int j = num_cols - 1;

        while (i < num_rows && j >= 0) {
            if (matrix[i][j] == target) {
                return true; // Target found!
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }

        return false; // Target not found within boundaries
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    bool result = solution.searchMatrix(matrix, target);
    cout << "Is the target " << target << " in the matrix? " << (result ? "Yes" : "No") << endl;

    return 0;
}