/*77. Combinations, Medium
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.
 
Example 1:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Example 2:
Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.

Constraints:
1 <= n <= 20
1 <= k <= n

Solution: iterate from 1 to n and use backtracking to generate all combinations of size k.
time: O(n choose k) * k, space: O(k) for the recursion stack and O(n choose k) for the result storage.
space: O(k) for the recursion stack and O(n choose k) for the result storage. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(1, n, k, path, res);
        return res;
    }

private:
    void backtrack(int start, int n, int k, vector<int>& path, vector<vector<int>>& res) {
        // Base case: combination of size k found
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        // Loop with pruning: stop if remaining elements are fewer than needed
        for (int i = start; i <= n - (k - path.size()) + 1; ++i) {
            path.push_back(i);                // Choose
            backtrack(i + 1, n, k, path, res); // Explore
            path.pop_back();                  // Unchoose (Backtrack)
        }
    }
};

int main() {
    Solution sol;
    int n = 4, k = 2;
    vector<vector<int>> result = sol.combine(n, k);
    for(const auto& comb : result) {
        cout << "[";
        for(size_t i = 0; i < comb.size(); ++i) {
            cout << comb[i];
            if(i < comb.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}