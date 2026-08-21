/*58. Length of Last Word, Easy
Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

 

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

Constraints:
1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.

Solution: We can solve this problem by iterating through the string from the end to the beginning, skipping any trailing spaces, and then counting the length of the last word until we hit a space or the beginning of the string. This approach ensures that we only traverse the string once, making it efficient.
time complexity: O(n), where n is the length of the string s. We may need to traverse the entire string in the worst case.
Space complexity: O(1), as we are using a constant amount of extra space for variables.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n - 1;
        
        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        // Count the length of the last word
        int length = 0;
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length;
    }
};

int main() {
    Solution solution;
    string s = "   fly me   to   the moon  ";
    cout << "Length of last word: " << solution.lengthOfLastWord(s) << endl; // Output: 4
    return 0;
}