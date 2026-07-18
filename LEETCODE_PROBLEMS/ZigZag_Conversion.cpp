/*6. Zigzag Conversion, Medium
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"


Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

Solution: We can solve by creatig a 2D vector of size numRows and then iterating through the string and placing the characters in the appropriate row. We can use a variable to keep track of the current row and a boolean variable to keep track of whether we are moving down or up. When we reach the last row, we change the direction to up and when we reach the first row, we change the direction to down. Finally, we can concatenate all the rows to get the final result.

time: O(n) - We iterate through the string once and place the characters in the appropriate row.
space: O(n) - We use a 2D vector of size numRows to store the characters in the appropriate row.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= static_cast<int>(s.size()))
        {
            return s;
        }

        string result;
        result.reserve(s.size());
        int cycle = 2 * numRows - 2;

        for (int row = 0; row < numRows; row++)
        {
            for (int j = row; j < static_cast<int>(s.size()); j += cycle)
            {
                result += s[j];

                int diagonal = j + cycle - 2 * row;
                if (row != 0 && row != numRows - 1 && diagonal < static_cast<int>(s.size()))
                {
                    result += s[diagonal];
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string result = solution.convert(s, numRows);
    cout << result << endl; // Output: "PAHNAPLSIIGYIR"
    return 0;
}