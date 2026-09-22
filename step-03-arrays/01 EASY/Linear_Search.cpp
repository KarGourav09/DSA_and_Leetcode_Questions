/*Linear Search in C
Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

Example 1:
Input:
 arr[] = 1 2 3 4 5, num = 3  
Output:
 2  `
Explanation:
 3 is present at the 2nd index of the array.
*/

#include <iostream>
#include <array>
using namespace std;

int LinearSearch (int arr[],int n, int num)
{
    while(n > 0)
    {
        if(arr[n - 1] == num)
            return n;
        n--;
    }
    return -1;
}

int main()
{
    int n = 5;
    int arr[n] = {1, 2, 4, 3, 5};
    int num = 3;
    cout << LinearSearch(arr, n, num) << endl;
}