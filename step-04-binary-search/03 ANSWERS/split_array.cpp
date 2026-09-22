/*410. Split Array Largest Sum, Hard
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.



Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.


Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)

Solution: The problem can be solved using binary search. 
The idea is to find the minimum largest sum that can be achieved by splitting the array into k subarrays. 
We can use binary search to find this minimum largest sum by checking if a given sum can be achieved with k subarrays.

Algorithm
Place the 2 pointers i.e. low and high: Initially, we will place the pointers. 
The pointer low will point to max(arr[]) and the high will point to sum(arr[]).

Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division.

Eliminate the halves based on the number of subarrays returned by countPartitions(): We will pass the potential value of ‘maxSum’, represented by the variable 'mid', to the ‘countPartitions()' function. 
This function will return the number of partitions we can make.

If partitions > k: On satisfying this condition, we can conclude that the number ‘mid’ is smaller than our answer. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).

Otherwise, the value mid is one of the possible answers. But we want the minimum value. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution
{
public:

    int CountSubarray (vector<int> &nums, int k, int mid)
    {
        int count = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > mid)
            {
                sum = nums[i];
                count++;
            }
        }
        return count;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int result = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int count = CountSubarray(nums, k, mid);
            if (count > k)
            {
                low = mid + 1;
            }
            else
            {
                result = mid;
                high = mid - 1;
            }
        }
        return result;
    }
};

int main()
{
    int n = 5, k = 2;
    int arr[5] = {7, 2, 5, 10, 8};
    vector<int> nums(arr, arr + n);
    Solution solution;
    cout << solution.splitArray(nums, k) << endl;
}