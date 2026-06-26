/*151. Reverse Words in a String, Medium
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.


Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

Solution: We can solve this problem in-place with O(1) extra space by following these steps:
1. Reverse the entire string.
2. Iterate through the string and reverse each word back to its correct orientation.
3. Remove any extra spaces between words and at the beginning and end of the string.

          Time:  O(n)
          Space: O(1)
*/

#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution
{

public:
    string reverseWords(string s)
    {
        // Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.length();
        int wordIndex = 0;

        for (int start = 0; start < n; start++)
        {
            // Skip spaces to find the start of the next word
            if (s[start] != ' ')
            {
                // If this isn't the first word we are writing, add a single separating space
                if (wordIndex != 0)
                {
                    s[wordIndex++] = ' ';
                }

                // Find the end of the current word
                int end = start;
                while (end < n && s[end] != ' ')
                {
                    s[wordIndex++] = s[end++];
                }

                // Reverse the word back to its correct orientation in-place
                int wordLen = end - start;
                reverse(s.begin() + wordIndex - wordLen, s.begin() + wordIndex);

                // Move the outer loop index to the end of this word
                start = end;
            }
        }
        // Remove trailing space
        s.resize(wordIndex);
        return s;
    }
};

int main()
{
    Solution solution;
    string s = "the sky is blue";
    string result = solution.reverseWords(s);
    cout << result << endl; // Output: "blue is sky the"
    return 0;
}