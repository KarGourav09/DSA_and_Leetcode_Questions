/*15. 3Sum, Medium
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;

        int n = nums.size();
        int limit = n / 3;
        unordered_map<int, int> counts;

        for (int i = 0; i < n; i++) {

                counts[nums[i]]++;

                if (counts[nums[i]] > limit) {
                    if (find(result.begin(), result.end(), nums[i]) ==
                        result.end()) {
                        result.push_back(nums[i]);
                    }
                }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> result = s.majorityElement(nums);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}