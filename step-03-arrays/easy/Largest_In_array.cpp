/*Find the Largest element in an array
Problem Statement: Given an array, we have to find the largest element in the array.

Example 1:
Input:
 arr[] = {2, 5, 1, 3, 0}  
Output:
 5  
Explanation: 5 is the largest element in the array.
*/

#include <iostream>
#include <vector>

using namespace std;

int LargestElement (vector<int> arr) {
    int n = 0;
    int Largest = arr[0];
    while(n < arr.size())
    {
        if(arr[n] > Largest)
        {
            Largest = arr[n];
        }
        n++;
    }
    return Largest;
}

int main() {
    vector<int> arr = {2, 5, 1, 3, 0};
    cout << "Largest element in the array is: " << LargestElement(arr) << endl;
    return 0;
}