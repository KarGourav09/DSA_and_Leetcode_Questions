/*1021. Remove Outermost Parentheses, Easy
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
Example 3:

Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
 

Constraints:

1 <= s.length <= 105
s[i] is either '(' or ')'.
s is a valid parentheses string.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        // find the no of ( and ) in the string

        vector<string> v;

        int open = 0, close = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                open++;
            else
                close++;

        if(open == close)
        {
            v.push_back(s.substr(i - open - close + 1, open + close));
            open = 0;
            close = 0;
        }
        }

        // for each '(' == ')' we can remove the outermost parentheses or that we can keep each () sets inside a stack and and remove the outermost parentheses

        for(int i = 0; i < v.size(); i++)
        {
            // check if the string is primitive or not, if not then we can removw the outermost parentheses else we can keep it as it is, for each phase we can check if the no of '(' == ')' then we can remove the outermost parentheses else we can keep it as it is
            int open = 0, close = 0;

            for(int j = 0; j < v[i].length(); j++)
            {
                if(v[i][j] == '(')
                    open++;
                else
                    close++;

                if(open == close )
                {
                    v[i] = v[i].substr(1, v[i].length() - 2);
                    break;
                }
            }
        }
          // Return the entire string only containing the primitive strings after removing the outermost parentheses

        string ans = "";
        for(const string& str : v)
        {
            ans += str;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "(()())(())(()(()))";
    cout << sol.removeOuterParentheses(s) << endl; // Output: "()()()()(())"
    return 0;
}