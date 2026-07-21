/*1404. Number of Steps to Reduce a Number in Binary Representation to One
Medium
Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.
 

Example 1:

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1.  
Example 2:

Input: s = "10"
Output: 1
Explanation: "10" corresponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.  
Example 3:

Input: s = "1"
Output: 0
 

Constraints:

1 <= s.length <= 500
s consists of characters '0' or '1'
s[0] == '1'

Solution: We will first find the decimal representation of the binary number. then we will check if the number is even or odd. If it is even, we will divide it by 2 and increment the step count. If it is odd, we will add 1 to it and increment the step count. We will repeat this process until the number becomes 1.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int decimal = 0;
        for(int i = 0; i < n; i++){
            decimal = decimal * 2 + (s[i] - '0');
        }
        return Reduce(decimal);
    }

    int Reduce(int n){
        int steps = 0;
        if(n == 1) return steps;
        while(n != 1){
            if(n % 2 == 0){
                n /= 2;
            }else{
                n += 1;
            }
            steps++;
        }
        return steps;
    }
};

int main() {
    Solution sol;
    string s = "1101";
    cout << sol.numSteps(s) << endl; // Output: 6
    return 0;
}