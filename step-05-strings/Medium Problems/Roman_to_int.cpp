/*13. Roman to Integer, Easy
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].

Solution: 1. First we will create a map to store the values of each roman numeral.
          2. We will iterate through the string and for each character, 
          we will check if the next character has a greater value than the current character. 
          If it does, we will subtract the current character's value from the total. If it doesn't, 
          we will add the current character's value to the total.e.g. - In "IV", since V (5) is greater than I (1), 
          we subtract 1 from 5 to get 4.
          3. We will return the total as the result.

        Time:  O(n)
        Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

public:
    int romanToInt(string s) {
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
                total -= romanMap[s[i]];
            } else {
                total += romanMap[s[i]];
            }
        }
        return total;
    }
};

int main() {
    Solution solution;
    string s = "MCMXCIV";
    int result = solution.romanToInt(s);
    cout << "The integer value of the Roman numeral " << s << " is: " << result << endl; // Output: 1994

    string s2 = "LVIII";
    int result2 = solution.romanToInt(s2);
    cout << "The integer value of the Roman numeral " << s2 << " is: " << result2 << endl; // Output: 58

    string s3 = "III";
    int result3 = solution.romanToInt(s3);
    cout << "The integer value of the Roman numeral " << s3 << " is: " << result3 << endl; // Output: 3

    return 0;
}