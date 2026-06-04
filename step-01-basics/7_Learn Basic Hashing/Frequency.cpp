/*Count frequency of each element in the array
Problem Statement: Given an array, we have found the number of occurrences of each element in the array.

Example 1:
Input: arr[] = {10,5,10,15,10,5};
Output: 10  3
        5  2
        15  1
Explanation: 10 occurs 3 times in the array
5 occurs 2 times in the array
15 occurs 1 time in the array
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int frequency[n] = {0}; // Initialize frequency array with 0
    for (int i = 0; i < n; i++)
    {
        frequency[arr[i]]++; // Increment the frequency of the element
    }

    // Enter the target frequency to find the elements with that frequency
    int target;
    cout << "Enter the target frequency: ";
    cin >> target;

    // Print the frequency of that target frequency
    cout << "Elements with frequency " << target << ": " << frequency[target] << endl;

    return 0;
}