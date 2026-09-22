/*Find Second Smallest and Second Largest Element in an array
Problem Statement: Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

Examples
Example 1:
Input:
 [1, 2, 4, 7, 7, 5]  
Output:
  
Second Smallest : 2  
Second Largest : 5  
Explanation:
  The elements are sorted as 1, 2, 4, 5, 7, 7.  
Hence, the second smallest element is 2, and the second largest element is 5.*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> SortedArray(vector<int> arr){

    if(arr.size() < 2)
    {
        return {-1, -1};
    }

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i], arr[i+1]);
        }
    }
    return arr;
}

int main() {
    vector<int> arr = {1, 2, 4, 7, 7, 5};
    vector<int> sortedArr = SortedArray(arr);
    cout << "Second Smallest element in the array is: " << sortedArr[1] << endl;
    cout << "Second Largest element in the array is: " << sortedArr[sortedArr.size() - 2] << endl;
    return 0;
}