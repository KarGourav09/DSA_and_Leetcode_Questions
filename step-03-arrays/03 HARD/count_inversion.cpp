/*Count inversions in an array
Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).

Inversion of an array: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

Example 1:
Input Format: N = 5, array[] = {1,2,3,4,5}
Result: 0
Explanation: we have a sorted array and the sorted array has 0 inversions as for i < j you will never find a pair such that A[j] < A[i]. More clear example: 2 has index 1 and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an inversion.
*/

#include<iostream>
#include<vector>

using namespace std;

int merge(vector<int>& arr, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    vector<int> temp(right - left + 1);
    int inversions = 0;

    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }

    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while(j <= right)
    {
        temp[k++] = arr[j++];
    }

    for(int i = 0; i < k; i++)
    {
        arr[left + i] = temp[i];
    }

    return inversions;
}

int main()
{
    vector<int> arr = {1, 20, 6, 4, 5};
    int n = arr.size();
    int total_inversions = 0;

    for(int size = 1; size < n; size *= 2)
    {
        for(int left = 0; left < n - size; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, n - 1);
            total_inversions += merge(arr, left, mid, right);
        }
    }

    cout << "Total Inversions: " << total_inversions << endl;

    return 0;
}