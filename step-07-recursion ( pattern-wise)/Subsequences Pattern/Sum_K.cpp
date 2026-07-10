/*Count all subsequences with sum K
Problem Statement: Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.

Examples
Example 1:
Input :
 nums = [4, 9, 2, 5, 1] , k = 10
Output :
 2
Explanation :
 The possible subsets with sum k are [9, 1] , [4, 5, 1].

Example 2:
Input :
 nums = [4, 2, 10, 5, 1, 3] , k = 5
Output :
 3
Explanation :
 The possible subsets with sum k are [4, 1] , [2, 3] , [5].

 Solution: we will use a recursive function to generate all possible subsequences of the given array. For each subsequence, we will calculate its sum and check if it is equal to k. If it is, we will increment a counter. Finally, we will return the count of such subsequences.
 time: O(2^n) where n is the length of the input array. This is because for each element, we have two choices: either include it in the subsequence or exclude it. Therefore, the total number of subsequences is 2^n.
 space: O(n) for the recursion stack. In the worst case, the recursion stack can go up to n levels deep, where n is the length of the input array.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recurse(vector<int>& arr, int index, int current, int k) {
        if (index == arr.size()) {
            if (current == k) {
                return 1;
            }
            return 0;
        }
        // Pick the current element
        int pick = recurse(arr, index + 1, current + arr[index], k);
        // Do not pick the current element
        int notPick = recurse(arr, index + 1, current, k);
        return pick + notPick;
    }
    int countSubsequences(vector<int>& arr, int k) {
        return recurse(arr, 0, 0, k);
    }

};

int main() {
    Solution solution;
    vector<int> arr = {4, 9, 2, 5, 1};
    int k = 10;
    int result = solution.countSubsequences(arr, k);
    cout << "Number of subsequences with sum " << k << ": " << result << endl;
    return 0;
}
