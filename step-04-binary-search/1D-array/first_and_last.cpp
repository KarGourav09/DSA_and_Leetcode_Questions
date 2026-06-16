/*34. Find First and Last Position of Element in Sorted Array, Medium
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const size_t n = nums.size();

        if (n == 0) return {-1, -1};

        size_t left = 0, right = n;

        while (left < right) {
            const size_t mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }

        if (left == n || nums[left] != target) return {-1, -1};
        const size_t first = left;

        right = n;
        while (left < right) {
            const size_t mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        const size_t last = left - 1;

        return {static_cast<int>(first), static_cast<int>(last)};
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = s.searchRange(nums, target);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl; // Output: 3 4

    return 0;
}