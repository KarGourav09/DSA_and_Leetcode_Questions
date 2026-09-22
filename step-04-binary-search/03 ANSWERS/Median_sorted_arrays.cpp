/*4. Median of Two Sorted Arrays, Hard
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

Solution: The optimal approach to finding the median of two sorted arrays uses Binary Search to perform a partition on the smaller array. This achieves a time complexity of 
 and a space complexity of 
.

Core Logic for the Final Code (27:31 - 31:30):
Preparation: Always perform the binary search on the smaller array to ensure efficiency. If nums2 is smaller, swap it with nums1.
Binary Search: Use low (starting at 0) and high (length of the smaller array) to find the cut1 position. The corresponding cut2 is derived as 
.
Handling Edge Cases: Use INT_MIN for left-side partitions and INT_MAX for right-side partitions to handle cases where the partition falls at the very beginning or end of the arrays.
Validity Check: Verify the partition using the condition:
l1 <= r2
l2 <= r1 Where 
 are elements immediately to the left of the cuts and 
 are elements immediately to the right.
Calculate Median:
If total length is even: The median is 
.
If total length is odd: The median is 
.
If the initial condition is not met, the binary search range is adjusted: move high to mid - 1 if 
, or low to mid + 1 otherwise
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if (l1 > r2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.00000

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.50000

    return 0;
}