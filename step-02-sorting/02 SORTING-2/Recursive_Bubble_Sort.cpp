/*Recursive Bubble Sort Algorithm
Problem Statement: Given an array of N integers, write a program to implement the Recursive Bubble Sort algorithm.

Example 1:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: After sorting we get 9,13,20,24,46,52*/

#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    // Base case: If the array size is 1, it's already sorted
    if (n == 1)
    {
        return;
    }

    int didSwap = 0; // Flag to check if any swapping occurs

    // One pass of bubble sort. After this pass, the largest element is moved to the end.
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            didSwap = 1; // Set flag if swapping occurs
        }
    }

    if (didSwap == 0)
    {
        // If no swapping occurred, the array is already sorted
        return;
    }

    // Recursive call for the remaining array
    BubbleSort(arr, n - 1);
}

int main()
{
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    int arr[N];
    cout << "Enter the elements: ";
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    BubbleSort(arr, N);

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}