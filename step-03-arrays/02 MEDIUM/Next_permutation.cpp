/*31. Next Permutation, Medium
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,3,2]
Output: [2,1,3]

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100

Solution: We want to rearrange the array to form the next greater permutation. If that's not possible (i.e., it's the last permutation), we return the smallest one (i.e., sorted ascendingly).

To find this next permutation with minimal change, we need to find a digit that can be increased slightly to make the number bigger and then rearrange the remaining part to be the smallest possible.
1.Traverse from the end and find the first index where the current digit is smaller than the next one (this is the "breaking point").
2.Then again traverse from the end to find the first digit greater than the breaking point digit and swap them.
3.Finally, reverse the part of the array to the right of the breaking point to get the smallest next permutation.
4.If no such breaking point exists (entire array is descending), just reverse the whole array.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the breaking point
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) { // If a breaking point is found
            int j = n - 1;

            // Step 2: Find the first digit greater than the breaking point
            while (nums[j] <= nums[i]) {
                j--;
            }

            // Step 3: Swap the breaking point with this digit
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse the part to the right of the breaking point
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 2};
    solution.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}