/*402. Remove K Digits, Medium
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.

Solution: We will use a monotonic stack to solve this problem. We will iterate through the digits of the number and maintain a stack that will help us build the smallest possible number by removing k digits. If the current digit is smaller than the top of the stack and we still have digits to remove (k > 0), we pop from the stack. After processing all digits, if we still have digits to remove, we pop from the stack until k reaches 0. Finally, we construct the result from the stack, ensuring to remove any leading zeros. If the result is empty, we return "0".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && k > 0 && st.top() > num[i] - '0') {
                st.pop();
                k--;
            }
            st.push(num[i] - '0');
        }
        while (k > 0) {
            st.pop();
            k--;
        }

        if (st.empty())
            return "0";

        string ans = "";

        while (!st.empty()) {
            ans += (st.top() + '0');
            st.pop();
        }

        while(ans.size()!= 0 && ans.back() == 0){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans.empty() ? "0" : ans;
    }
};


int main() {
    Solution solution;
    string num = "1432219";
    int k = 3;
    cout << solution.removeKdigits(num, k) << endl; // Output: "1219"
    return 0;
}