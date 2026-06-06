/*Check if an Array is Sorted
Problem Statement: Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else return False.

Example 1:
Input: N = 5, array[] = {1,2,3,4,5}
Output: True.
Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next values, So the answer is True.*/

#include <iostream>
using namespace std;

bool isSorted(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false; // If any element is greater than the next one, it's not sorted
            }
        }
        return true; // If we reach here, the array is sorted
    }

    int main(){
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        int arr[n];
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (isSorted(arr, n)) {
            cout << "True. The array is sorted." << endl;
        } else {
            cout << "False. The array is not sorted." << endl;
        }
    }