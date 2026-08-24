/*45. Jump Game II, Medium
You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2
 
Constraints:
1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].

Solution: We can solve this problem using a greedy approach. The idea is to keep track of the farthest index we can reach with the current number of jumps and the farthest index we can reach with one more jump. We iterate through the array and update these values accordingly. When we reach the end of the current jump range, we increment the jump count and update the current jump range to the farthest index we can reach.
time: O(n), where n is the length of the input array nums. We iterate through the array once, making constant time updates to our jump counters and ranges.
space: O(1), as we are using a constant amount of extra space for our jump counters and ranges, regardless of the input size.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0; // Number of jumps made
        int currentEnd = 0; // The farthest index we can reach with the current
        int farthest = 0; // The farthest index we can reach with one more jump

        for(int i = 0; i < n - 1; i++){
            farthest = max(farthest, i + nums[i]);
            if(i == currentEnd){
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Minimum jumps for nums1: " << solution.jump(nums1) << endl; // Output: 2

    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Minimum jumps for nums2: " << solution.jump(nums2) << endl; // Output: 2

    return 0;
}