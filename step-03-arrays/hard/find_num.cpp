/*Find the repeating and missing numbers
Problem Statement: Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.
Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.

Note: You are not allowed to modify the original array.

Example 1:
Input:
 nums = [3, 5, 4, 1, 1]  
Output:
 [1, 2]  
Explanation:
 1 appears twice in the array, and 2 is missing from the array. So the output is [1, 2].
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> findErrorNums(vector<int>& nums)
{
    int n = nums.size();
    int sum = 0;
    int duplicate = 0;

    for(int i = 0; i < n; i++)
    {
        sum += nums[i];

        for(int j = i + 1; j < n; j++)
        {
            if(nums[i] == nums[j])
            {
                duplicate = nums[i];
                break;
            }
        }
    }
    int expected_sum = n * (n + 1) / 2;
    int missing = expected_sum - (sum - duplicate);
    
    return {duplicate, missing};
}

int main()
{
    vector<int> nums = {3, 5, 4, 1, 1};
    vector<int> result = findErrorNums(nums);

    for(int num : result)
    {
        cout << num << " ";
    }

    return 0;
}