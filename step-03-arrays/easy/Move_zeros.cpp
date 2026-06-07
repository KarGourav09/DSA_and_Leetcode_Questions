/*283. Move Zeroes, Easy
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Solution: we take an Index variable to keep track of the position of the first zero, 
and we iterate through the array, if we find a non-zero element, 
we swap it with the element at the zero index and increment the zero index. T
his way we move all the non-zero elements to the front of the array and all the zeros to the end.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIndex = 0;
        for(int i = 0; i <  nums.size(); i++)
        {
            if(nums[i] != 0  )
            {
                swap(nums[i], nums[zeroIndex]);
                zeroIndex++;
            }
            else
            {
                continue;
            }
        }
        
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0,1,0,3,12};
    s.moveZeroes(nums);
    for(int i : nums)
    {
        cout << i << " ";
    }
}
