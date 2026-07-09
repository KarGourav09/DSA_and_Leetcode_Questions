/*Power Set: Print all the possible subsequences of the String
Problem Description: Given a string, find all the possible subsequences of the string.

Examples
Input: str = "abc"
Output: [a, ab, abc, ac, b, bc, c]
Explanation: Given string has 7 subsequences.
Input: str = "aa"
Output: [a, a, aa] 
Explanation: Given string has 3 subsequences

Solution: We will use recursion to generate all possible subsequences of the string. At each step, we have two choices: either include the current character in the subsequence or exclude it. We will explore both possibilities recursively.

time: O(2^n) where n is the length of the string, as each character can either be included or excluded.
space: O(n) for the recursion stack, where n is the length of the string.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> PowerSet(string str){
        vector<string> result;
        string current;
        generateSubsequences(str, 0, current, result);
        return result;
    }

private:
    void generateSubsequences(const string& str, int index, string current, vector<string>& result) {
        if (index == str.length()) {
            result.push_back(current);
            return;
        }
        // Exclude the current character
        generateSubsequences(str, index + 1, current, result);
        // Include the current character
        generateSubsequences(str, index + 1, current + str[index], result);
    }
};

int main() {
    Solution sol;
    string str = "abc";
    vector<string> result = sol.PowerSet(str);
    cout << "All possible subsequences of the string \"" << str << "\": ";
    for (const auto& subseq : result) {
        cout << subseq << " ";
    } 
    cout << endl;
    return 0;
}