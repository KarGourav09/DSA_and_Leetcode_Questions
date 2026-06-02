/*9. Palindrome Number
Solved
Easy

Given an integer x, return true if x is a palindrome,
and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.*/

#include <iostream>
using namespace std;

bool Palindrome(int x)
{
    if(x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }
    int rev = 0;
    while (x > rev)
    {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return x == rev || x == rev / 10;
}

int main()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;
    Palindrome(x);
    if (Palindrome(x))
    {
        cout << x << " is a palindrome number." << endl;
    }
    else
    {
        cout << x << " is not a palindrome number." << endl;
    }
}