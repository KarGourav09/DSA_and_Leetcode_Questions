/*Factorial of a Number : Iterative and Recursive
Problem Statement: Given a number X,  print its factorial.

To obtain the factorial of a number, it has to be multiplied by all the whole numbers preceding it. More precisely X! = X*(X-1)*(X-2) … 1.

Note: X  is always a positive number. 

Example 1:
Input:
 X = 5
Output:
 120
Explanation:
 5! = 5*4*3*2*1
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int FactorialNum(int n) {
    if (n == 1) {
        return 1;
    }
    return n * FactorialNum(n - 1);
}
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Solution sol;
    cout << "Factorial of " << n << " is: " << sol.FactorialNum(n) << endl;
    return 0;
}