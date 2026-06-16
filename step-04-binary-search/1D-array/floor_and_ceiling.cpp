/*Floor and Ceil in Sorted Array
Problem Statement: ou're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1]. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x

Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.*/

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> Floor_and_Ceil (vector<int> &arr, int x)
{
    int n = arr.size();

    int left = 0, right = n - 1;

    int floor = -1, ceil = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            floor = arr[mid];
            ceil = arr[mid];
            break;
        }
        else if (arr[mid] < x) {
            floor = arr[mid];
            left = mid + 1;
        }
        else {
            ceil = arr[mid];
            right = mid - 1;
        }
    }
    return {floor, ceil};
}

int main() {
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int x = 5;

    pair<int, int> result = Floor_and_Ceil(arr, x);
    cout << "Floor: " << result.first << ", Ceil: " << result.second << endl; // Output: Floor: 4, Ceil: 7

    return 0;
}