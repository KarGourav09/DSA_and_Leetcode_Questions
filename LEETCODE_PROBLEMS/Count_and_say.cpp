/*38. Count and Say, Medium
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing each maximal group of consecutive identical characters with the concatenation of the length of the group followed by the character itself. For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15", and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.

 

Example 1:
Input: n = 4
Output: "1211"
Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"

Example 2:
Input: n = 1
Output: "1"
Explanation:

This is the base case.

 

Constraints:
1 <= n <= 30
 

Follow up: Could you solve it iteratively?

Solution: The problem can be solved iteratively by generating the count-and-say sequence up to the nth term. We start with the base case "1" and repeatedly apply the run-length encoding to generate the next term in the sequence.

time: O(n * m), where m is the length of the string generated at each step
space: O(m), where m is the length of the string generated at each step
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; i++) {
            string next = "";
            int j = 0;
            while (j < result.length()) {
                char c = result[j];
                int count = 0;
                while (j < result.length() && result[j] == c) {
                    count++;
                    j++;
                }
                next += to_string(count) + c;
            }
            result = next;
        }
        return result;
    }
};

int main() {
    Solution solution;
    int n = 4;
    string result = solution.countAndSay(n);
    cout << "The " << n << "th term of the count-and-say sequence is: " << result << endl;
    return 0;
}