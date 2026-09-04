/*3903. Smallest Stable Index I, Easy
You are given an integer array nums of length n and an integer k.
For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).
In other words:

max(nums[0..i]) is the largest value among the elements from index 0 to index i.
min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
An index i is called stable if its instability score is less than or equal to k.

Return the smallest stable index. If no such index exists, return -1.

 

Example 1:

Input: nums = [5,0,1,4], k = 3

Output: 3

Explanation:

At index 0: The maximum in [5] is 5, and the minimum in [5, 0, 1, 4] is 0, so the instability score is 5 - 0 = 5.
At index 1: The maximum in [5, 0] is 5, and the minimum in [0, 1, 4] is 0, so the instability score is 5 - 0 = 5.
At index 2: The maximum in [5, 0, 1] is 5, and the minimum in [1, 4] is 1, so the instability score is 5 - 1 = 4.
At index 3: The maximum in [5, 0, 1, 4] is 5, and the minimum in [4] is 4, so the instability score is 5 - 4 = 1.
This is the first index with an instability score less than or equal to k = 3. Thus, the answer is 3.
Example 2:

Input: nums = [3,2,1], k = 1

Output: -1

Explanation:

At index 0, the instability score is 3 - 1 = 2.
At index 1, the instability score is 3 - 1 = 2.
At index 2, the instability score is 3 - 1 = 2.
None of these values is less than or equal to k = 1, so the answer is -1.
Example 3:

Input: nums = [0], k = 0

Output: 0

Explanation:

At index 0, the instability score is 0 - 0 = 0, which is less than or equal to k = 0. Therefore, the answer is 0.

 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
0 <= k <= 109

Solution: We can solve this problem by iterating through the array and calculating the instability score for each index. We can maintain two variables to keep track of the maximum value seen so far (max_so_far) and the minimum value from the current index to the end of the array (min_from_i). We can update these variables as we iterate through the array. If we find an index where the instability score is less than or equal to k, we return that index. If no such index is found, we return -1.
Time complexity: O(n), where n is the length of the nums array, since we are iterating through the array once.
Space complexity: O(1), since we are using a constant amount of extra space for the variables max_so_far and min_from_i.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int max_so_far = INT_MIN;
        int min_from_i = INT_MAX;

        // Precompute the minimum values from the end of the array
        vector<int> min_from_end(n);
        min_from_end[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            min_from_end[i] = min(nums[i], min_from_end[i + 1]);
        }

        for (int i = 0; i < n; ++i) {
            max_so_far = max(max_so_far, nums[i]);
            min_from_i = min_from_end[i];

            if (max_so_far - min_from_i <= k) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {5, 0, 1, 4};
    int k1 = 3;
    cout << "Output: " << solution.firstStableIndex(nums1, k1) << endl; // Output: 3

    vector<int> nums2 = {3, 2, 1};
    int k2 = 1;
    cout << "Output: " << solution.firstStableIndex(nums2, k2) << endl; // Output: -1

    vector<int> nums3 = {0};
    int k3 = 0;
    cout << "Output: " << solution.firstStableIndex(nums3, k3) << endl; // Output: 0

    return 0;
}