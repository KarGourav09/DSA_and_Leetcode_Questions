/*Length of the longest subarray with zero Sum
Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

Example 1:
Input:
 N = 6, array[] = {9, -3, 3, -1, 6, -5}  
Result:
 5  
Explanation:
 The following subarrays sum to zero:
- {-3, 3}
- {-1, 6, -5}
- {-3, 3, -1, 6, -5}
The length of the longest subarray with sum zero is 5.*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{public:
    int maxLen(vector<int>& arr, int n)
    {
        unordered_map<int, int> prefixSumMap;

        int maxLength = 0;
        int prefixSum = 0;

        for(int i = 0; i < n; i++)
        {
            prefixSum += arr[i];

            if(prefixSum == 0)
            {
                maxLength = i + 1;
            }
            else if(prefixSumMap.find(prefixSum) != prefixSumMap.end())
            {
                int length = i - prefixSumMap[prefixSum];
                maxLength = max(maxLength, length);
            }
            else
            {
                prefixSumMap[prefixSum] = i;
            }
        }
        return maxLength;
    }
};

int main()
{
    int n = 8;
    vector<int> arr = {6, -2, 2, -8, 1, 7, 4, -10};

    Solution solution;
    int result = solution.maxLen(arr, n);
    cout << "Length of the longest subarray with zero sum: " << result << endl;

    return 0;
}