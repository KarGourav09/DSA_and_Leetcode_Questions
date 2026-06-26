/*1903. Largest Odd Number in String, Easy
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
 

Constraints:

1 <= num.length <= 105
num only consists of digits and does not contain any leading zeros.

Solution: 1. We will iterate through the string from the end to the beginning.
          2. For each character, we will check if it is an odd digit (1, 3, 5, 7, 9).
          3. If we find an odd digit, we will return the substring from the start of the string to that index (inclusive).
          4. If we reach the beginning of the string without finding any odd digit, we will return an empty string.

            Time:  O(n)
            Space: O(1)
*/

#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {

        // Iterate from the end of the string to find the first odd digit
        for (int i = num.length() - 1; i >= 0; i--) {
            // Check if the digit is odd by converting the character to an integer and checking if it's odd
            if ((num[i] - '0') % 2 == 1) {
                // Return the substring from the start of the string to the index of the first odd digit found
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main() {
    Solution solution;
    string num = "52";
    string result = solution.largestOddNumber(num);
    cout << "Largest odd number in the string: " << result << endl; // expected output: "5"
    return 0;
}