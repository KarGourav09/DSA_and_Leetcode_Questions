/*Find the Missing Number
Given an array arr[] of size n-1 with distinct integers in the range of [1, n]. This array represents a permutation of the integers from 1 to n with one element missing. Find the missing element in the array.

Examples: 
Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMissing (vector<int> arr){
    int n = arr.size() + 1;

    // Calculate the sum of numbers from 1 to n
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    // Calculate the expected sum of numbers from 1 to n
    int expectedSum = n * (n + 1) / 2;

    // The missing number is the difference between expected sum and actual sum
    return expectedSum - sum;
}

int main()
{
    vector<int> arr = {8, 2, 4, 5, 3, 7, 1};

    int result = findMissing(arr);

    cout << "The missing number is: " << result << endl;

    return 0;
}