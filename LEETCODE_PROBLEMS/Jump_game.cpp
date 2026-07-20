/*55. Jump Game, Medium
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105

Solution: Here a greedy approach works, we can keep track of the maximum index we can reach at each step. If at any point, the maximum reachable index is less than or equal to the current index, we cannot proceed further and return false. If we can reach or exceed the last index, we return true.

time: O(n), where n is the length of the input array nums. We traverse the array once, updating the maximum reachable index at each step.
space: O(1), we use a constant amount of space to store the maximum reachable index.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    cout << boolalpha; // Print boolean values as true/false
    cout << "Can jump in nums1: " << solution.canJump(nums1) << endl; // Output: true
    cout << "Can jump in nums2: " << solution.canJump(nums2) << endl; // Output: false

    return 0;
}