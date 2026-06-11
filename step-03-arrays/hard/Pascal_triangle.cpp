/*118. Pascal's Triangle, Easy
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 
Constraints:
1 <= numRows <= 30
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> result(numRows);

        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j == 0 || j == i)
                {
                    result[i].push_back(1);
                }
                else
                {
                    result[i].push_back(result[i-1][j-1] + result[i-1][j]);
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    int numRows = 5;
    vector<vector<int>> result = s.generate(numRows);

    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}