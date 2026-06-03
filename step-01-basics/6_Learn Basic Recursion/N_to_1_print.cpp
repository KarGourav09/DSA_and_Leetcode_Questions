/*Print N to 1 using Recursion
Problem Description: Given an integer N, write a program to print numbers from N to 1.

Examples
Input: N = 4
Output: 4, 3, 2, 1
Explanation: All the numbers from 4 to 1 are printed.
Input: N = 1
Output: 1 
Explanation: This is the base case.*/

#include <iostream>

using namespace std;

class Solution {
public:
    void printNum(int n) {
    if (n <= 0) {
        return;
    }
    cout << n << " ";
    printNum(n - 1);
}
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Solution sol;
    sol.printNum(n);
    return 0;
}