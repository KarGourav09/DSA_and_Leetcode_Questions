/*Check if the given String is Palindrome or not
Problem Statement: Given a string, check if the string is palindrome or not. A string is said to be palindrome if the reverse of the string is the same as the string.

Example 1:
Input: Str =  “ABCDCBA”
Output: Palindrome
Explanation: String when reversed is the same as string.
*/

/*Alternate approach
class Solution{
    public:
    bool isPalindrome(string str)
    {
        if (str.length() == 1) {
            return true; // A single character is considered a palindrome
        }
        if (str.empty()) {
            return true; // An empty string is considered a palindrome
        }
        int start = 0;
        int end = str.length() - 1;

        while (start < end){
            if (str[start] != str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    Solution solution;
    if (solution.isPalindrome(str)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}*/

#include <iostream>
#include <string>

using namespace std;


bool palindrome(int i, string& s)
{
    if( i >= s.length()/2)
        return true;
        
    if (s[i] != s[s.length() - i - 1])
    {
        return false;
    }

    return palindrome(i + 1, s);
}


int main()
{
    string s = "madam";

    cout << palindrome(0, s); // 1 means palindrome, 0 means not palindrome
    cout << endl;
    return 0;
}
