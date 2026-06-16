/*Implement Upper Bound
Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.

What is Upper Bound?
The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.

The upper bound is the smallest index, ind, where arr[ind] > x.

Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] > x.
*/

#include <iostream>
#include <vector>

using namespace std;

int upper_bound(vector<int> &arr, int x)
{
    int n = arr.size();

    int low = 0, high = n - 1;
    int ans = n; // Initialize ans to n, which is the size of the array

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] > x)
        {
            ans = mid; // Update ans to the current mid index
            high = mid - 1; // Search in the left half
        }
        else
        {
            low = mid + 1; // Search in the right half
        }
    }
    return ans; // Return the upper bound index
}

int main()
{
    int N = 4;
    vector<int> arr = {1, 2, 2, 3};
    int x = 2;

    int result = upper_bound(arr, x);
    cout << "The upper bound index of " << x << " is: " << result << endl;

    return 0;
}