/*85. Maximal Rectangle, Hard
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1

Constraints:
rows == matrix.length
cols == matrix[i].length
1 <= rows, cols <= 200
matrix[i][j] is '0' or '1'.

Solution: Treat each row as the base of a histogram. The height of each column is updated as rows are processed, and a monotonic stack finds the largest rectangle in that histogram. The time complexity is O(n*m), and the space complexity is O(m), where n is the number of rows and m is the number of columns.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        int element, nse, pse;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                element = st.top();
                st.pop();

                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxArea = max(heights[element] * (nse - pse - 1), maxArea);
            }
            st.push(i);
        }

        while (!st.empty())
        {
            nse = n;
            element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();

            maxArea = max(heights[element] * (nse - pse - 1), maxArea);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>> &matrix){
        if(matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = 0;
        vector<int> heights(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    int result = solution.maximalRectangle(matrix);
    cout << "Maximal Rectangle Area: " << result << endl;

    return 0;
}