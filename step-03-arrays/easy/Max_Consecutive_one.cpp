/*485. Max Consecutive Ones, Easy
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                count++;
                maxCount = max(maxCount, count);
            } else if(nums[i] == 0 && count > 0) {
                count = 0;
            }
        }
        return maxCount;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << solution.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}