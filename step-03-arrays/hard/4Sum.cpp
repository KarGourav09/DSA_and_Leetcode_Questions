/*18. 4Sum, Medium
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 3; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            // Optimization Pruning: 
            // If the smallest possible sum is greater than target, no point continuing
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            // If the largest possible sum with this 'i' is less than target, skip to next 'i'
            if ((long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;

            for(int j = left; j < n - 2; j++)
            {
                if(j > left && nums[j] == nums[j - 1]) continue;

                int left2 = j + 1;
                int right2 = n - 1;

                // Optimization Pruning for 'j':
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;

                while(left2 < right2)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[left2] + nums[right2];

                    if(sum == target)
                    {
                        result.push_back({nums[i], nums[j], nums[left2], nums[right2]});
                        left2++;
                        right2--;

                        while(left2 < right2 && nums[left2] == nums[left2 - 1]) left2++;
                        while(left2 < right2 && nums[right2] == nums[right2 + 1]) right2--;
                    } else if(sum < target) {
                        left2++;
                    } else {
                        right2--;
                    }
                }
            }
            
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> result = s.fourSum(nums, target);
    for (const auto& quadruplet : result)
    {
        cout << "[";
        for (int i = 0; i < quadruplet.size(); i++)
        {
            cout << quadruplet[i];
            if (i < quadruplet.size() - 1) cout << ",";
        }
        cout << "]";
    }
    cout << endl;
    return 0;
}