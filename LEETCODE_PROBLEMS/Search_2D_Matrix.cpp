/*74. Search a 2D Matrix
Medium
Topics
premium lock icon
Companies
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Solution: We can Use the Staircase Search Algorithm to solve this problem. 
We will start from the top-right corner of the matrix and compare the current element with the target. 
If the current element is equal to the target, we have found the target and can return true. 
If the current element is greater than the target, we can eliminate the current column by moving left. 
If the current element is less than the target, we can eliminate the current row by moving down. 
We will continue this process until we either find the target or exhaust our search space.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int num_rows = matrix.size();
        int num_cols = matrix[0].size();

        // Start at the top-right corner
        int i = 0;
        int j = num_cols - 1;

        while (i < num_rows && j >= 0) {
            if (matrix[i][j] == target) {
                return true; // Target found!
            }
            else if (matrix[i][j] > target) {
                j--; // Target is smaller, eliminate this entire column by moving left
            }
            else {
                i++; // Target is larger, eliminate this entire row by moving down
            }
        }

        return false; // Target not found within boundaries
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target;
    cout << "Enter the target value: ";
    cin >> target;

    Solution solution;
    bool found = solution.searchMatrix(matrix, target);
    cout << "Target " << target << (found ? " found." : " not found.") << endl; // Output: Target 3 found.

    return 0;
}