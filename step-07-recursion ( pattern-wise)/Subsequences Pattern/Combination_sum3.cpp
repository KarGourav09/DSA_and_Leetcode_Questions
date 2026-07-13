/*216. Combination Sum III, Medium
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 

Constraints:

2 <= k <= 9
1 <= n <= 60

Solution: We will use Backtracking to find all the combinations of k numbers that sum up to n. 
We will start with an empty combination and recursively add numbers from 1 to 9, ensuring that we do not exceed the desired sum and that we do not use the same number more than once. 
When we reach a combination of size k that sums to n, we will add it to our result list.
If the current combination equals to the desired sum and the size of the combination is less than k, we will backtrack and try the next number.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int k, int n, int start, vector<int>& combination, vector<vector<int>>& result) {
        if (combination.size() == k && n == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i <= 9; ++i) {
            if (n - i < 0) break; // No need to continue if the sum exceeds n
            combination.push_back(i);
            backtrack(k, n - i, i + 1, combination, result); // Move to the next number
            combination.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(k, n, 1, combination, result);
        return result;
    }
};

int main() {
    Solution sol;
    int k = 3, n = 7;
    vector<vector<int>> result = sol.combinationSum3(k, n);
    
    for (const auto& comb : result) {
        cout << "[";
        for (size_t i = 0; i < comb.size(); ++i) {
            cout << comb[i];
            if (i < comb.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}