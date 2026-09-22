/*Recursive Insertion Sort Algorithm
Problem Statement: Given an array of N integers, write a program to implement the Recursive Insertion Sort algorithm.

Example 1:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: After sorting we get 9,13,20,24,46,52*/

#include <iostream>
using namespace std;

void InsertionSort(int arr[], int i, int n)
{
    if (i == n)
        return;

    int j = i;

    while (j > 0 && arr[j] > arr[j - 1])
    {
        swap(arr[j], arr[j - 1]);
        j--;
    }
    InsertionSort(arr, i + 1, n);
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    InsertionSort(arr, 1, n);

    cout << "Sorted array: ";
    for (int i = n - 1; i >= 0; i--)
        cout << arr[i] << " ";

    return 0;
}