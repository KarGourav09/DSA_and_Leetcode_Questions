/*Check if there exists a subsequence with sum K
Problem Statement: Given an array nums and an integer k. Return true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.

Examples
Example 1:
Input :
 nums = [1, 2, 3, 4, 5] , k = 8
Output :
 Yes
Explanation :
 The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.

Example 2:
Input :
 nums = [4, 3, 9, 2] , k = 10
Output :
 No
Explanation :
 No subsequence can sum up to 10.
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
    bool existsSubsequence(vector<int>& arr, int k) {
        return recurse(arr, 0, 0, k) > 0;
    }

};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 8;
    bool result = solution.existsSubsequence(arr, k);
    if (result) {
        cout << "Yes, there exists a subsequence with sum " << k << endl;
    } else {
        cout << "No, there does not exist a subsequence with sum " << k << endl;
    }
    return 0;
}