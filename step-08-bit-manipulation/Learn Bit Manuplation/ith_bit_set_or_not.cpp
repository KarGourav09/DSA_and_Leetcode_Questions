/*Check if the i-th bit is set or not
Problem Statement: Given two integers n and i, return true if the ith bit in the binary representation of n (counting from the least significant bit, 0-indexed) is set (i.e., equal to 1). Otherwise, return false.

Example 1:
Input: 
n = 5, i = 0
Output: 
true
Explanation: 
Binary representation of 5 is 101. The 0-th bit from LSB is set (1).

Example 2:
Input: 
n = 10, i = 1
Output: 
true
Explanation: 
Binary representation of 10 is 1010. The 1-st bit from LSB is set (1).

*/

#include <bits/stdc++.h>
using namespace std;

/*class Solution {
public:
    bool checkIthBit(int n, int i){
        string binary = "";
        while(n > 0){
            binary += to_string(n % 2);
            n /= 2;
        }

        if(binary[i] == '1'){
            return true;
        }
        else{
            return false;
        }
    }
};
*/

// Using Bit Manipulation to Check if the i-th Bit is Set
class Solution {
public:
    bool checkIthBit(int n, int i) {
        return (n & (1 << i)) != 0;
    }
};

int main() {
    Solution sol;
    int n, i;
    cout << "Enter the number (n): ";
    cin >> n;
    cout << "Enter the bit position (i): ";
    cin >> i;

    bool result = sol.checkIthBit(n, i);
    if(result){
        cout << "The " << i << "-th bit is set." << endl;
    }
    else{
        cout << "The " << i << "-th bit is not set." << endl;
    }

    return 0;
}
