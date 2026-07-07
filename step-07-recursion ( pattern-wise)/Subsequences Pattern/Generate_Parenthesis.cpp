/*22. Generate Parentheses, Medium
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:
1 <= n <= 8


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void backtrack(vector<string>& ans, string current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }
        if (open < n) {
            backtrack(ans, current + "(", open + 1, close, n);
        }
        if (close < open) {
            backtrack(ans, current + ")", open, close + 1, n);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
};

int main() {
    int n = 3; // Example input
    Solution solution;
    vector<string> result = solution.generateParenthesis(n);

    // Output the result
    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}