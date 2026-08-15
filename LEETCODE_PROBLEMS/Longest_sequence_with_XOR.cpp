/*3702. Longest Subsequence With Non-Zero Bitwise XOR, Medium
You are given an integer array nums.

Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

 
Example 1:
Input: nums = [1,2,3]
Output: 2
Explanation:
One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.

Example 2:
Input: nums = [2,3,4]
Output: 3
Explanation:
The longest subsequence is [2, 3, 4]. The bitwise XOR is computed as 2 XOR 3 XOR 4 = 5, which is non-zero.

Constraints:
1 <= nums.length <= 105
0 <= nums[i] <= 109

Solution: We will XOR all the elements of the array. If the result is non-zero, we can take all the elements as a subsequence. If the result is zero at that instance we count that sequence as the largest subsequence with non-zero XOR and resume the XOR operation with the next element. We will keep track of the maximum length of such subsequences and return it at the end.
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int total_xor = 0;
        bool has_non_zero = false;

        for (int num : nums) {
            total_xor ^= num;
            if (num != 0) {
                has_non_zero = true;
            }
        }

        if (total_xor != 0) {
            return n;
        }
        if (has_non_zero) {
            return n - 1;
        }
        return 0;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3};
    cout << "Output: " << solution.longestSubsequence(nums1) << endl; // Output: 2

    vector<int> nums2 = {2, 3, 4};
    cout << "Output: " << solution.longestSubsequence(nums2) << endl; // Output: 3

    vector<int> nums3 = {0, 7};
    cout << "Output: " << solution.longestSubsequence(nums3) << endl; // Output: 2

    return 0;
}