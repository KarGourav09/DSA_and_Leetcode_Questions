/*Problem Statement: Given two integers N1 and N2, find their greatest common divisor.

Example 1:
Input: N1 = 9, N2 = 12

Output: 3
Explanation:
Factors of 9: 1, 3, 9
Factors of 12: 1, 2, 3, 4, 6, 12
Common Factors: 1, 3
Greatest common factor: 3 (GCD)

solution: Wrote a function using recursion to find the GCD of two numbers 
using Euclidean algorithm. The function takes two integers as input and
 returns their GCD. In the main function, we take input from the user and call the 
 GCD function to get the result, which is then printed to the console.
*/

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;
    cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd(n1, n2) << endl;
    return 0;
}