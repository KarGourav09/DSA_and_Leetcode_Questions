/*Median of Row Wise Sorted Matrix

Problem Statement:
Given a row-wise sorted matrix of size M*N, where M is no. of rows and N is no. of columns, find the median in the given matrix.
Note: M*N is odd.

Examples
Input: M = 3, N = 3, matrix[][] =

1 4 9
2 5 6
3 8 7
Output: 5
Explanation:
If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. Therefore, median = 5
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{

private:
    int countSmallerThanEqualToMid(vector<int> &row, int mid)
    {
        return upper_bound(row.begin(), row.end(), mid) - row.begin();
    }

public:
    int median(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[0][n - 1];

        for (int i = 1; i < m; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][n - 1]);
        }

        int desired = (m * n + 1) / 2;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int count = 0;

            for (int i = 0; i < m; i++)
            {
                count += countSmallerThanEqualToMid(matrix[i], mid);
            }

            if (count < desired)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 4, 9},
        {2, 5, 6},
        {3, 8, 7}};
    cout << sol.median(matrix) << endl; // Output: 5
    return 0;
}