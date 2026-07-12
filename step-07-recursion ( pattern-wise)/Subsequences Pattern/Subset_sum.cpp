/*Subset Sum : Sum of all Subsets
Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.

Examples

Input: N = 3, arr[] = {5,2,1}
Output: 0,1,2,3,5,6,7,8
Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8

Input: N=3,arr[]= {3,1,2}
Output: 0,1,2,3,3,4,5,6
Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6

Solution: Using recursion we can generate all the subsets and then we can find the sum of each subset and store it in a vector. 
Finally we can sort the vector and print the result.
1. Create a recursive function that takes the current index, the current sum, and the array as parameters.
2. In the recursive function, if the current index is equal to the size of the array, add the current sum to a result vector and return.
3. Otherwise, call the recursive function twice: once including the current element in the sum and once excluding it.
4. After the recursive calls, sort the result vector and print the sums.

time: O(2^N) for generating all subsets and O(M log M) for sorting the sums, where M is the number of unique sums generated.
space: O(M) for storing the sums in the result vector.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> Helper(int index, int sum, vector<int> &arr, vector<int> &result){
        if(index == arr.size()){
            result.push_back(sum);
            return result;
        }
        Helper(index + 1, sum, arr, result); // If we don't include the current element in the sum
        Helper(index + 1, sum + arr[index], arr, result); // If we include the current element in the sum
        return result;
    }

    vector<int> subsetSum(int N, vector<int> arr){
        vector<int> result;
        Helper(0, 0, arr, result);
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    int N = 3;
    vector<int> arr = {5, 2, 1};
    Solution sol;
    vector<int> result = sol.subsetSum(N, arr); // Output: 0,1,2,3,5,6,7,8
    for(int sum : result){
        cout << sum << " ";
    }
    return 0;
}