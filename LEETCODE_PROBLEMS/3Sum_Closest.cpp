/*16. 3Sum Closest, Medium
Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.
Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104

Solution: Sort the array and use two pointers to find the best pair for each fixed element.

time: O(n^2) where n is the length of the input array nums. We sort once O(n log n) and iterate through the array with two pointers O(n^2).
space: O(1) since we are not using any additional data structures that scale with the input size. We only use a few variables.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if(sum == target) {
                    return sum;
                }
                
                if(abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }
                
                if(sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return closest;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << sol.threeSumClosest(nums, target) << endl; // Output: 2
    return 0;
}