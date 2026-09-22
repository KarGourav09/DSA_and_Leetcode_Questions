/*90. Subsets II
Medium
Topics
premium lock icon
Companies
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10

Solution: we will use a recursive approach to generate all possible subsets of the given array. 
To handle duplicates, we will first sort the array and then use a backtracking technique to explore all combinations while skipping over duplicate elements.

time: O(2^n * n) where n is the number of elements in the array.
space: O(n) for the recursion stack and O(2^n) for storing the subsets.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void powerSet(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans){
        if(index >= nums.size()){
            ans.push_back(ds);
            return;
        }
        // CHOICE 1: Include the current element
        ds.push_back(nums[index]);
        powerSet(index + 1, nums, ds, ans);
        ds.pop_back();       
        // CHOICE 2: Exclude the current element
        while(index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }
        powerSet(index + 1, nums, ds, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        powerSet(0, nums, ds, ans);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = obj.subsetsWithDup(nums);
    
    // Printing the output
    for(auto it : ans){
        cout << "[ ";
        for(auto i : it){
            cout << i << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}