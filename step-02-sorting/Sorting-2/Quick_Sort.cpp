/*Quick Sort Algorithm
Problem Statement: Given an array of n integers, sort the array using the Quicksort method.

Examples
Input: N = 5, Arr[] = {4,1,7,9,3}
Output: {1, 3, 4, 7, 9}
Explanation: After sorting the array in ascending order it becomes 1, 3, 4, 7, 9*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }
    
    int partition(int arr[], int low, int high) {
        int pivot = arr[low];
        int i = low;
        int j = high;
    
        while (i < j) {
            // Find an element greater than the pivot from the left
            while (arr[i] <= pivot && i <= high - 1) {
                i++;
            }
            // Find an element smaller than the pivot from the right
            while (arr[j] > pivot && j >= low + 1) {
                j--;
            }
            // If pointers haven't crossed, swap the out-of-place elements
            if (i < j) {
                std::swap(arr[i], arr[j]);
            }
        }
        
        // Swap the pivot element into its correct final position (index j)
        std::swap(arr[low], arr[j]); 
        return j; // Return the partitioning index
    }
};

int main() {
    int arr[] = {4, 1, 7, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    Solution solution;
    solution.quickSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}