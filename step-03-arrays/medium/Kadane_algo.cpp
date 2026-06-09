/*Kadane's Algorithm : Maximum Subarray Sum in an Array
Problem Statement: Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.
Can you print the subarray that has the maximum sum?

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input:
 nums = [-2,1,-3,4,-1,2,1,-5,4]
Output:
 6
Explanation:
 The subarray from index 3 to index 6 has the largest sum = 6, which is the maximum sum of any contiguous subarray.*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    int maxSubArray(const vector<int> &nums)
    {
        long long maxSum = 0;
        long long currentSum = 0;
        int start = 0;

        int maxStart = -1;
        int maxEnd = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            currentSum += nums[i];

            if (currentSum > maxSum)
            {
                maxSum = currentSum;
                maxStart = start;
                maxEnd = i;
            }

            if (currentSum < 0 || currentSum == 0)
            {
                currentSum = 0;
                start = i + 1;
            }
        }

        cout << "Maximum Subarray: ";
        for (int i = maxStart; i <= maxEnd; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;

        return maxSum;
    }
};

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Create an instance of Solution class
    Solution sol;

    int maxSum = sol.maxSubArray(arr);

    // Print the max subarray sum
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}