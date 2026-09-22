/*Merge Sort Algorithm
Problem Statement: Given an array of size n, sort the array using Merge Sort.

Examples
Input : N=7,arr[]={3,2,8,5,1,4,23}
Output : {1,2,3,4,5,8,23}
Explanation : Given array is sorted in non-decreasing order.*/

#include <iostream>
#include <vector>

using namespace std;

// Step 2: The Merge function (combines two sorted halves)
void MergeSort(vector<int>& arr, int low, int high) {

    if (low >= high) return; // Base case: Stop when size is 1

    int mid = low + (high - low) / 2;

    MergeSort(arr, low, mid);      // Split left half
    MergeSort(arr, mid + 1, high); // Split right half

    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Compare elements from both halves and grab the smaller one
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    // Copy any leftover elements from the left side
    while (left <= mid) {
        temp.push_back(arr[left++]);
    }

    // Copy any leftover elements from the right side
    while (right <= high) {
        temp.push_back(arr[right++]);
    }

    // Copy the sorted elements back into our original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}


int main() {
    vector<int> arr = {3, 2, 8, 5, 1, 4, 23};
    
    // 0 is the starting index, arr.size() - 1 is the last index
    MergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}