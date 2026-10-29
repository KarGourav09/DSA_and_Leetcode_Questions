/*84. Largest Rectangle in Histogram
Hard
Topics
premium lock icon
Companies
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.



Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4


Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104

Solution:
*/

// Method-2

#include <bits/stdc++.h>
using namespace std;

class Solution
{
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
};

int main()
{
    Solution s;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << s.largestRectangleArea(heights) << endl; // Output: 10
    return 0;
}
