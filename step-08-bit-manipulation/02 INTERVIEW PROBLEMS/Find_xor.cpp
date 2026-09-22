/*Find XOR of numbers from L to R
Problem Statement: Given two integers L and R. Find the XOR of the elements in the range [L , R].

Examples
Example 1:
Input :
 L = 3 , R = 5
Output :
 2
Explanation : 
answer = (3 ^ 4 ^ 5) = 2.

Example 2:
Input :
 L = 1, R = 3
Output :
 0
Explanation : 
answer = (1 ^ 2 ^ 3) = 0.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorfromLtoR(int L, int R){
        int result = L;
        for (int i = L + 1; i <= R; i++)
        {
            result ^= i;
        }
        return result;
    }
};

int main() {
    int L = 3, R = 5;
    Solution sol;
    cout << sol.xorfromLtoR(L, R) << endl; // Output: 2
    return 0;
}