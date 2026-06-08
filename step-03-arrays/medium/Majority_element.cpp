/*169. Majority Element, Easy
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    unordered_map<int, int> count;
    for(int i = 0; i < nums.size(); i++)
    {
        count[nums[i]]++;
    }

    int majority = nums[0];
    for(const auto& i : count)
    {
        if(i.second > count[majority])
        {
            majority = i.first;
        }
    }
    return majority;
}
};

int main()
{
    vector<int> nums = {3,2,3};

    Solution solution;
    int majority = solution.majorityElement(nums);
    cout << "The majority element is: " << majority << endl;

    return 0;
}