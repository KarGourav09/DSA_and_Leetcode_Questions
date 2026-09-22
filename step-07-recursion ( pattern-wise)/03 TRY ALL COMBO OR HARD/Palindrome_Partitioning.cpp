/*Palindrome partitioning
Given a string s partition string s such that every substring of partition is palindrome. Return all possible palindrome partition of string s.


Example 1

Input : s = "aabaa"

Output : [ [ "a", "a", "b", "a", "a"] , [ "a", "a", "b", "aa"] , [ "a", "aba", "a"] , [ "aa", "b", "a", "a"] , [ "aa", "b", "aa" ] , [ "aabaa" ] ]

Explanation : Above all are the possible ways in which the string can be partitioned so that each substring is a palindrome.

Example 2

Input : s = "baa"

Output : [ [ "b", "a", "a"] , [ "b", "aa" ] ]

Explanation : Above all are the possible ways in which the string can be partitioned so that each substring is a palindrome.

Solution: We can solve this problem using backtracking. We will explore all possible partitions of the string and check if each substring is a palindrome. If it is, we will add it to the current partition and continue to explore further partitions. When we reach the end of the string, we will add the current partition to the result.

time: O(N * 2^N), where N is the length of the string. In the worst case, we can have 2^N possible partitions, and for each partition, we may need to check if each substring is a palindrome, which takes O(N) time.
space: O(N), where N is the length of the string. The space complexity is due to the recursion stack and the space used to store the current partition.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        int n = s.size();

        vector<vector<string>> res;
        vector<string> cur;
        function<void(int)> dfs = [&](int idx){
            if (idx == n) { res.push_back(cur); return; }
            for (int j = idx; j < n; ++j) {
                string part = s.substr(idx, j-idx+1);
                if (isPalindrome(part)) {
                    cur.push_back(part);
                    dfs(j+1);
                    cur.pop_back();
                }
            }
        };
        dfs(0);
        return res;
    }
private:
    bool isPalindrome(const string &t){
        int i=0,j=t.size()-1; while(i<j){ if(t[i++]!=t[j--]) return false; } return true;
    }
};

int main() {
    Solution sol;
    string s = "aabaa";
    vector<vector<string>> result = sol.partition(s);
    
    cout << "[ ";
    for (const auto& partition : result) {
        cout << "[ ";
        for (const auto& str : partition) {
            cout << "\"" << str << "\", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;

    return 0;
}