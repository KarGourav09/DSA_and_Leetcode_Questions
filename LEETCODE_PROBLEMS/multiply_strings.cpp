/*43. Multiply Strings, Medium
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 
Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.

Solution: We can simulate the multiplication process as we do it by hand. We will multiply each digit of the first number by each digit of the second number and keep track of the carry. The result will be stored in a vector, and we will convert it to a string at the end.

time: O(n * m), where n and m are the lengths of num1 and num2 respectively.
space: O(n + m), for the result vector.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int n = num1.length();
        int m = num2.length();
        vector<int> result(n + m, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + result[p2];
                
                result[p2] = sum % 10;
                result[p1] += sum / 10;
            }
        }
        
        string ans = "";
        for (int i = 0; i < n + m; i++) {
            if (!(ans.empty() && result[i] == 0)) {
                ans += to_string(result[i]);
            }
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    string num1 = "123";
    string num2 = "456";
    cout << "Product of " << num1 << " and " << num2 << " is: " << solution.multiply(num1, num2) << endl;
    return 0;
}