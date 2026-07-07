/*Generate all binary strings
Problem Statement: Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.

A binary string is a string consisting only of characters '0' and '1'.

Examples
Example 1:
Input:
 n = 3  
Output:
 ["000", "001", "010", "100", "101"]  
Explanation:
 All binary strings of length 3 that do not contain consecutive 1s.

Example 2:
Input:
 n = 2  
Output:
 ["00", "01", "10"]  
Explanation:
 All binary strings of length 2 that do not contain consecutive 1s.
 */

 #include <bits/stdc++.h>
 using namespace std;

 class Solution {
public:
    void solve(int n, string str, vector<string> &ans){
        if(n == 0){
            ans.push_back(str);
            return;
        }
        solve(n-1, str + '0', ans);
        if(str.empty() || str.back() == '0'){
            solve(n-1, str + '1', ans);
        }
    }
 public:
   vector<string> generateBinaryStr(int n){
        vector<string> ans;
        string str = "";
        solve(n, str, ans);
        return ans;
    }
};

int main(){
    int n = 3;
    Solution obj;
    vector<string> ans = obj.generateBinaryStr(n);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}