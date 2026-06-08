/*Longest Subarray with given Sum K(Positives)
Problem Statement: Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

Example 1:
Input:
 nums = [10, 5, 2, 7, 1, 9], k = 15  
Output:
 4  
Explanation:
 The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.*/

#include <iostream>
#include <vector>

using namespace std;

int SubArray (vector<int>& arr, int k)
{
    int sum = 0;
    int maxLength = 0;
    int start = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        while(sum > k)
        {
            sum -= arr[start];
            start++;
        }

        if(sum == k)
        {
            maxLength = max(maxLength, i - start + 1);
        }
    }
    return maxLength;
}

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;

    int result = SubArray(arr, k);
    cout << "The length of the longest sub-array that sums to " << k << " is: " << result << endl;

    return 0;
}