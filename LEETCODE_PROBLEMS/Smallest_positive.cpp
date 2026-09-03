/*3718. Smallest Missing Multiple of K, Easy
Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.

A multiple of k is any positive integer divisible by k.

 

Example 1:

Input: nums = [8,2,3,4,6], k = 2

Output: 10

Explanation:

The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.

Example 2:

Input: nums = [1,4,7,10,15], k = 5

Output: 5

Explanation:

The multiples of k = 5 are 5, 10, 15, 20... and the smallest multiple missing from nums is 5.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 100

solution: We can solve this problem by iterating through the multiples of k starting from k itself and checking if each multiple is present in the nums array. We can use a set to store the elements of nums for O(1) average time complexity lookups. The first multiple of k that is not found in the set will be our answer.
time complexity: O(n + m), where n is the length of nums and m is the number of multiples of k we need to check until we find the missing one. In the worst case, m can be up to 100/k, but since k is at least 1, this is manageable within the constraints.
space complexity: O(n), where n is the length of nums, due to the storage of the set containing the elements of nums.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> numSet(nums.begin(), nums.end());
        int multiple = k;
        while (numSet.count(multiple)) {
            multiple += k;
        }
        return multiple;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {8, 2, 3, 4, 6};
    int k1 = 2;
    cout << "Output: " << solution.missingMultiple(nums1, k1) << endl; // Output: 10

    vector<int> nums2 = {1, 4, 7, 10, 15};
    int k2 = 5;
    cout << "Output: " << solution.missingMultiple(nums2, k2) << endl; // Output: 5

    return 0;
}