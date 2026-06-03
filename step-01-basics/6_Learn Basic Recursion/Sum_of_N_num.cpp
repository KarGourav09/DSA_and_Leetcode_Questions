/*Sum of first N Natural Numbers
Problem Statement: Given a number ‘N’, find out the sum of the first N natural numbers .

Examples

Input: N=6
Output: 21
Explanation: 1+2+3+4+5+6=21*/

#include <iostream>

using namespace std;

class Solution {
public:
    int SumNum(int n) {
    if (n == 1) {
        return 1;
    }
    return n + SumNum(n - 1);
}
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Solution sol;
    cout << "Sum of first " << n << " natural numbers is: " << sol.SumNum(n) << endl;
    return 0;
}