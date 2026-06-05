/*Selection Sort Algorithm
Problem Statement: Given an array of N integers, write a program to implement the Selection sorting algorithm.

Example 1:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: After sorting the array is: 9, 13, 20, 24, 46, 52*/

#include <iostream>
#include <vector>

using namespace std;

void SelectionSort (vector<int>& arr)
{
    int n = arr.size();

    for(int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if(minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    int N;
    cout << "Enter the number of elements in the array: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    SelectionSort(arr);

    return 0;
}