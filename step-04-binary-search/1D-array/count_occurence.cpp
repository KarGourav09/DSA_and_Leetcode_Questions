/*Count Occurrences in Sorted Array
Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

Example 1:
Input:
 N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output
: 4
Explanation:
 3 is occurring 4 times in
the given array so it is our answer.
*/

#include <iostream>
#include <vector>

using namespace std;

int CountOccur(vector<int> &arr, int N, int x)
{
    if (N == 0)
        return {-1};

    int left = 0, right = N;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }

    if (left == N || arr[left] != x)
        return {-1};
    int first = left;

    right = N;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= x)
            left = mid + 1;
        else
            right = mid;
    }
    int last = left - 1;

    return last - first + 1;
}

int main()
{
    vector<int> arr = {2, 2, 3, 3, 3, 3, 4};
    int N = arr.size();
    int x = 3;
    int result = CountOccur(arr, N, x);
    cout << result << endl; // Output: 4

    return 0;
}