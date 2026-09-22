/*560. Subarray Sum Equals K, Medium
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Constraints:
1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> prefixSumCount;

        int prefixSum = 0;
        int count = 0;

        prefixSumCount[0] = 1; // Base case: there's one way to have a prefix sum of 0 (by taking no elements)

        for(int i = 0; i < n; i++)
        {
            prefixSum += nums[i];

            int remove = prefixSum - k;

            if(prefixSumCount.find(remove) != prefixSumCount.end())
            {
                count += prefixSumCount[remove];
            }

            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3};
    int k = 3;

    int result = solution.subarraySum(nums, k);
    cout << "Number of subarrays that sum to " << k << ": " << result << endl;
}

/*
Brute Force Approach:

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            int sum = 0;

            for (int j = i; j < nums.size(); j++) {

                sum += nums[j];

                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
*/