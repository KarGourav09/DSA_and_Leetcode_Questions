/*3875. Construct Uniform Parity Array I, Easy
You are given an array nums1 of n distinct integers.
You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.
For each index i, you must choose exactly one of the following (in any order):

nums2[i] = nums1[i]
nums2[i] = nums1[i] - nums1[j], for an index j != i
Return true if it is possible to construct such an array, otherwise, return false.

 

Example 1:

Input: nums1 = [2,3]

Output: true

Explanation:

Choose nums2[0] = nums1[0] - nums1[1] = 2 - 3 = -1.
Choose nums2[1] = nums1[1] = 3.
nums2 = [-1, 3], and both elements are odd. Thus, the answer is true​​​​​​​.
Example 2:

Input: nums1 = [4,6]

Output: true

Explanation:​​​​​​​

Choose nums2[0] = nums1[0] = 4.
Choose nums2[1] = nums1[1] = 6.
nums2 = [4, 6], and all elements are even. Thus, the answer is true.
 

Constraints:

1 <= n == nums1.length <= 100
1 <= nums1[i] <= 100
nums1 consists of distinct integers.

Solution: The solution is to check if the array contains at least one odd and one even number. If it does, we can always construct a uniform parity array by choosing the appropriate elements. If the array contains only odd or only even numbers, we can directly use those numbers to form the uniform parity array.
time complexity: O(n), where n is the length of the input array nums1. We need to iterate through the array once to check for the presence of odd and even numbers.
space complexity: O(1), as we are using a constant amount of extra space to store the flags for odd and even numbers.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {2, 3};
    cout << (solution.uniformArray(nums1) ? "true" : "false") << endl; // Output: true

    nums1 = {4, 6};
    cout << (solution.uniformArray(nums1) ? "true" : "false") << endl; // Output: true

    nums1 = {1, 3, 5};
    cout << (solution.uniformArray(nums1) ? "true" : "false") << endl; // Output: false

    nums1 = {2, 4, 6};
    cout << (solution.uniformArray(nums1) ? "true" : "false") << endl; // Output: false

    return 0;
}