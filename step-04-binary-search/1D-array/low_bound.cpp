/*Implement Lower Bound
Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

What is lower bound?
The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 1
Explanation: Index 1 is the smallest index such that arr[1] >= x.

Solution Approach:
1. Brute Force Approach: We can iterate through the array and check for the first index
    where the value is greater than or equal to x. This approach has a time complexity of O(N).
2. Optimal Approach: We can use binary search to find the lower bound efficiently. The time complexity of this approach is O(log N).
*/

#include <iostream>
#include <vector>

using namespace std;

int lower_bound(const vector<int>& arr, int x)
{
    int n = arr.size();
    int left = 0, right = n;

    while(left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < x) {
            left = mid + 1; // Move right
        } else {
            right = mid; // Move left
        }
    }
    return left;
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int x = 2;

    int result = lower_bound(arr, x);
    cout << "Lower bound of " << x << " is at index: " << result << endl; // Output: 1

    return 0;
}

/*
Brute Force Approach:

int lower_bound(const vector<int>& arr, int x)
{
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        if (arr[i] >= x) {
            return i; // Return the index of the first element greater than or equal to x
        }
    }
    return n; // Return the size of the array if no such index is found
}

*/