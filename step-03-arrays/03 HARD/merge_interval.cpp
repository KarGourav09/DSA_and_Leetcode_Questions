/*56. Merge Intervals, Medium
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
 
Constraints:
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        vector<vector<int>> mergedIntervals;

        for(int i = 0; i < n; i++)
        {
            if (mergedIntervals.empty() || intervals[i][0] > mergedIntervals.back()[1])
            {
                mergedIntervals.push_back(intervals[i]);
            }
            else 
            {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
            }
        }
        return mergedIntervals;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> mergedIntervals = solution.merge(intervals);

    for(size_t i = 0; i < mergedIntervals.size(); i++)
    {
        cout << "[" << mergedIntervals[i][0] << "," << mergedIntervals[i][1] << "]";
        if(i != mergedIntervals.size() - 1)
        {
            cout << ",";
        }
    }
    cout << endl;

    return 0;
}