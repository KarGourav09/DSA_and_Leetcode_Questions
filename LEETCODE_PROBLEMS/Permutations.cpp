/*46. Permutations, Medium
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

Solution: Use backtracking to generate all permutations. Start with an empty permutation and at each step, add an unused number from the input array to the current permutation. Once the current permutation has the same length as the input array, add it to the result list.

time: O(n * n!) where n is the length of the input array, since there are n! permutations and generating each permutation takes O(n) time.
space: O(n) for the recursion stack and the current permutation being built.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(n, false);
        backtrack(nums, current, used, result);
        return result;
    }
private:
    void backtrack(const vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                current.push_back(nums[i]);
                backtrack(nums, current, used, result);
                current.pop_back();
                used[i] = false;
            }
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol;
    vector<vector<int>> permutations = sol.permute(nums);
    
    for (const auto& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}