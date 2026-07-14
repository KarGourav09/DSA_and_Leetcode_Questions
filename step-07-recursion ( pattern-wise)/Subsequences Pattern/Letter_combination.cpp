/*17. Letter Combinations of a Phone Number, Medium
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

1 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Helper(string digits, int index, string current, vector<string>& result, unordered_map<string, string>& phone){

        if(index == digits.size()){
            result.push_back(current);
            return;
        }

        string letters = phone[digits.substr(index, 1)];
        for(char letter : letters){
            Helper(digits, index + 1, current + letter, result, phone);
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<string, string> phone = {
            {"2", "abc"}, {"3", "def"}, {"4", "ghi"}, {"5", "jkl"},
            {"6", "mno"}, {"7", "pqrs"}, {"8", "tuv"}, {"9", "wxyz"}
        };
        vector<string> result;
        if(digits.empty()) return result;
        string current;

        Helper(digits, 0, current, result, phone);
        return result;
    }
};

int main() {
    Solution solution;
    string digits = "23";
    vector<string> combinations = solution.letterCombinations(digits);

    cout << "Letter combinations for digits \"" << digits << "\":\n";
    for (const string& combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}