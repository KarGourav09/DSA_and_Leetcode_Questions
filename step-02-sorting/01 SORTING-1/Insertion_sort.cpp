/*Insertion Sort Algorithm
Problem Statement: Given an array of integers called nums, sort the array in non-decreasing order using the insertion sort algorithm and return the sorted array.

A sorted array in non-decreasing order is an array where each element is greater than or equal to all preceding elements in the array.

Example 1:
Input:
  nums = [7, 4, 1, 5, 3]  
Output:
  [1, 3, 4, 5, 7]  
Explanation:
  The array is sorted in non-decreasing order: 1 ≤ 3 ≤ 4 ≤ 5 ≤ 7.
*/

#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int> &nums) {
    int n = nums.size();
    for(int i=0; i < n; i++)
    {
        int Key = nums[i];
        int j = i-1;

        while(j >= 0 && nums[j] > Key) {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = Key;
    }

    cout << "Sorted array: ";
    for(int i=0; i < n; i++)    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;
    vector<int> nums(N);
    cout << "Enter the elements: ";
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    InsertionSort(nums);
    return 0;
}