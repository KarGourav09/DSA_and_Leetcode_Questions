/*1752. Check if Array Is Sorted and Rotated, Easy
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].

Solution: We can use the bubble sort approach and add a condition that only one roation per element is allowed. If we find more than one rotation, we can return false. If we successfully sort the array with at most one rotation per element, we can return true.
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Use the modulo operator (%) to handle the wrap-around comparison seamlessly
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            
            // Optimization: If we see more than 1 drop, we can fail early
            if (count > 1) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    
    Solution solution;
    bool result = solution.check(nums);
    
    cout << (result ? "true" : "false") << endl; // Output: true
    
    return 0;
}

