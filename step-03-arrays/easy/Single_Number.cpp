/*136. Single Number, Easy
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for (int i : nums) {
            xorr = xorr ^ i;
        }
        return xorr;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {4,1,2,1,2};
    int result = solution.singleNumber(nums);
    cout << "The single number is: " << result << endl;
    return 0;
}