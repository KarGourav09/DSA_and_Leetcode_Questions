/*Print Fibonacci Series up to Nth term
Problem Statement: Given an integer N. Print the Fibonacci series up to the Nth term.

Example 1:
Input: N = 5
Output: 0 1 1 2 3 5
Explanation: 0 1 1 2 3 5 is the fibonacci series up to 5th term.(0 based indexing*/

#include <iostream>
using namespace std;

class Solution
{public:
    int Fibo(int n)
    {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else
            return Fibo(n - 1) + Fibo(n - 2);
    }
};

int main()
{
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci series up to " << n << "th term: ";
    Solution sol;
    cout << sol.Fibo(n); // Print the nth term
    cout << endl;

    return 0;
}


/*Alternate sol- usinf for loop

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}*/