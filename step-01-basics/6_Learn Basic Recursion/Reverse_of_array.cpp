/*Reverse a given Array
Problem Statement: You are given an array. The task is to reverse the array and print it.

Examples
Input: N = 5, arr[] = {5,4,3,2,1}
Output: {1,2,3,4,5}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.*/

/*STL method:
class Solution {
public:
    // Function to reverse the array using STL reverse function
    void reverseArray(vector<int>& arr) {
        // Use STL reverse to reverse array in-place
        reverse(arr.begin(), arr.end());
    }
};*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{ public:
    void reverseArray(vector<int> &arr, int length)
    {
        for (int i = 0, j = length - 1; i < j; ++i, --j)
        {
            swap(arr[i], arr[j]);
        }
    }
};

int main()
{
    int N = 5;
    vector<int> arr = {5, 4, 3, 2, 1};
    Solution ob;
    ob.reverseArray(arr, N);
    for (int i = 0; i < N; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}