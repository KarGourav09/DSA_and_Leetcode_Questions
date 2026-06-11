/*54. Spiral Matrix, Medium
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        
        int m = matrix[0].size();
        int n = matrix.size();

        int top = 0;
        int bottom = n - 1;
        int right = m - 1;
        int left = 0;

        while(top <= bottom && left <= right)
        {
            for(int i = left; i <= right; i++)
            {
                result.push_back(matrix[top][i]);
            }

            for(int i = top + 1; i <= bottom; i++)
            {
                result.push_back(matrix[i][right]);
            }

            if(top < bottom)
            {
                for(int i = right - 1; i >= left; i--)
                {
                    result.push_back(matrix[bottom][i]);
                }
            }

            if(left < right)
            {
                for(int i = bottom - 1; i > top; i--)
                {
                    result.push_back(matrix[i][left]);
                }
            }

            top++;
            bottom--;
            left++;
            right--;

        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result = solution.spiralOrder(matrix);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}