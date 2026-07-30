/*47. Permutations II, Medium
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order. 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10

Solution: instead of focusing on the number we can focus on the index of a number. We can use a boolean array to keep track of which indices have been used in the current permutation. This way, we can avoid generating duplicate permutations by skipping over indices that have already been used.

time: O(n * n!) where n is the length of the input array. The n! factor comes from generating all permutations, and the additional n factor comes from the time taken to copy each permutation into the result list.
space: O(n) for the recursion stack and the boolean array used to track which indices have been used.

Optimization: We can optimize the solution by sorting the input array first. This way, we can easily skip over duplicate numbers during the permutation generation process, ensuring that we only generate unique permutations.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, current, used, result);
        return result;
    }
private:
    void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, current, used, result);
            current.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = sol.permuteUnique(nums);
    
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}