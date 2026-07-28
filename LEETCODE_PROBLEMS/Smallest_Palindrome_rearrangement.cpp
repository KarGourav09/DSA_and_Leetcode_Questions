/*3517. Smallest Palindromic Rearrangement I, Medium
You are given a palindromic string s.

Return the lexicographically smallest palindromic permutation of s.
 

Example 1:
Input: s = "z"

Output: "z"

Explanation:
A string of only one character is already the lexicographically smallest palindrome.

Example 2:
Input: s = "babab"

Output: "abbba"

Explanation:
Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.

Example 3:
Input: s = "daccad"

Output: "acddca"

Explanation:
Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.

Constraints:
1 <= s.length <= 105
s consists of lowercase English letters.
s is guaranteed to be palindromic.

Solution: To find the lexicographically smallest palindromic permutation of a given palindromic string, we can follow these steps:
1. Count the frequency of each character in the string.
2. Create a list of characters that will form the first half of the palindrome. For each character, take half of its frequency (integer division) and add it to the list.
3. Sort the list of characters to ensure lexicographical order.
4. Construct the first half of the palindrome from the sorted list.
5. If the length of the original string is odd, find the middle character (the one with an odd frequency) and place it in the middle of the palindrome.
6. Finally, concatenate the first half, the middle character (if any), and the reverse of the first half to form the complete palindrome.

time: O(n log n) where n is the length of the string s, due to sorting the characters.
space: O(n) for storing the character frequencies and the first half of the palindrome.

optimization: We can optimize the space complexity by using a fixed-size array of size 26 (for lowercase English letters) to count character frequencies instead of using a hash map. This reduces the space used for counting frequencies to O(1) since the size of the array is constant.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a']++;
        }

        int left = 0, right = n - 1;
        
        for(int i = 0; i < 26; i++) {
            while (freq[i] >= 2) {
                s[left++] = 'a' + i;
                s[right--] = 'a' + i;
                freq[i] -= 2;
            }
        }
        return s;        
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a palindromic string: ";
    cin >> s;

    string result = sol.smallestPalindrome(s);
    cout << "The lexicographically smallest palindromic permutation is: " << result << endl;

    return 0;
}