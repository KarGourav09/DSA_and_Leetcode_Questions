/*Subset - II | Print all the Unique Subsets
Problem Statement: Given an integer array nums, which can have duplicate entries, provide the power set. Duplicate subsets cannot exist in the solution set. Return the answer in any sequence.

Examples
Input: array[] = [1,2,2]
Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]
Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.

Input: array[] = [1]
Output: [ [ ], [1] ]
Explanation: Only two unique subsets are available.
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

    vector<vector<int>> subsetsWithoutDup(vector<int>& nums){
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end()); // Sorting is essential for duplicate grouping
        powerSet(0, nums, ds, ans);
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = obj.subsetsWithoutDup(nums);
    
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