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
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int SubArray (vector<int>& arr)
{
    int sum = 0;
    int maxLength = 0;

    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            maxLength = max(maxLength, i + 1);
        }
        else if (map.find(sum) == map.end())
        {
            map[sum] = i;
        }
        else
        {
            maxLength = max(maxLength, i - map[sum]);
        }
    }
    return maxLength;
}

int main()
{
    vector<int> arr = {9, -3, 3, -1, 6, -5};

    int result = SubArray(arr);
    cout << "The length of the longest sub-array that sums to 0 is: " << result << endl;

    return 0;
}