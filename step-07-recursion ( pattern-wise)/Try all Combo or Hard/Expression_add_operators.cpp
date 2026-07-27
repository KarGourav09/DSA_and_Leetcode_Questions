/*282. Expression Add Operators, Hard
Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.

Note that a number can contain multiple digits.

Example 1:
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

Example 2:
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.

Example 3:
Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
 

Constraints:

1 <= num.length <= 10
num consists of only digits.
-231 <= target <= 231 - 1

Solution: We are given three arithmetic operators (+, -, *). we can use a function that tries all the combinations of the operators in between the digits of the string num. We can use recursion to generate all possible expressions and evaluate them to check if they equal the target value.

time: O(4^n) where n is the length of the string num, since for each digit we have 4 choices (no operator, +, -, *).
space: O(n) for the recursion stack and the space used to store the current expression.

Optimisation: We can optimize the evaluation of the expression by keeping track of the current value and the previous operand, so we don't have to evaluate the entire expression each time. This allows us to handle multiplication correctly by adjusting the current value based on the previous operand.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string num, int target, int index, long long current, long long previous, string expression, vector<string> &result) {
        if (index == num.length()) {
            if (current == target) {
                result.push_back(expression);
            }
            return;
        }

        for (int i = index; i < num.length(); i++) {
            string operand_str = num.substr(index, i - index + 1);
            long long operand = stoll(operand_str);

            if (index == 0) {
                solve(num, target, i + 1, operand, operand, operand_str, result);
            } else {
                solve(num, target, i + 1, current + operand, operand, expression + "+" + operand_str, result);
                solve(num, target, i + 1, current - operand, -operand, expression + "-" + operand_str, result);
                solve(num, target, i + 1, current - previous + previous * operand, previous * operand, expression + "*" + operand_str, result);
            }

            if (num[index] == '0') {
                break;
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        solve(num, target, 0, 0, 0, "", result);
        return result;
    }
};

int main() {
    Solution solution;
    string num = "123";
    int target = 6;
    vector<string> result = solution.addOperators(num, target);
    
    for (const string &expr : result) {
        cout << expr << endl;
    }
    
    return 0;
}