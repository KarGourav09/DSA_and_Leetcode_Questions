/*75. Sort Colors, Medium
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

    unordered_map<int, int> count;
    for (int i = 0; i < nums.size(); i++)
    {
        count[nums[i]]++;
    }

    int index = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            nums[index] = i;
            index++;
        }
    }
}
};

int main()
{
    vector<int> nums = {2,0,2,1,1,0};

    Solution solution;
    solution.sortColors(nums);
    cout << "The sorted colors are: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}