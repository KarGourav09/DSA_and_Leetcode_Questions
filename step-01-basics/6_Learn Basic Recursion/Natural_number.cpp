/*Print 1 to N using Recursion
Problem Description: Given an integer N, write a program to print numbers from 1 to N.

Examples
Input: N = 4
Output: 1, 2, 3, 4
Explanation: All the numbers from 1 to 4 are printed.
Input: N = 1
Output: 1 
Explanation: This is the base case.*/

#include <iostream>

using namespace std;

class Solution {
public:
    void printNum(int i, int n) {
        if ( n <= 0) {
            return;
        }
        if (i > n) {
            return;
        }
        cout << i << " ";
        printNum(i + 1, n);
    }
};

int main()
{
    int i = 1, n;
    cout << "Enter a number: ";
    cin >> n;
    Solution sol;
    sol.printNum(1, n);
    return 0;
}