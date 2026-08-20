/*57. Insert Interval, Medium
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Two intervals are considered overlapping if they share at least one point.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it. 

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 
Constraints:
0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105

Solution: Iterate through the intervals and check for overlaps with the new interval. If there is no overlap, add the interval to the result. If there is an overlap, merge the intervals. Finally, add any remaining intervals to the result.
Time complexity: O(n), where n is the number of intervals.
space complexity: O(n) for the result storage.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool inserted = false;
        
        for (const auto& interval : intervals) {
            if (!inserted) {
                if (interval[1] < newInterval[0]) {
                    result.push_back(interval);
                } else if (interval[0] > newInterval[1]) {
                    result.push_back(newInterval);
                    result.push_back(interval);
                    inserted = true;
                } else {
                    newInterval[0] = min(newInterval[0], interval[0]);
                    newInterval[1] = max(newInterval[1], interval[1]);
                }
            } else {
                result.push_back(interval);
            }
        }
        
        if (!inserted) {
            result.push_back(newInterval);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> result = sol.insert(intervals, newInterval);
    
    for (const auto& interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}