/*Check if the Number is Armstrong

You are given an integer n. You need to check whether it is an armstrong number or not.
Return true if it is an armstrong number, otherwise return false.

An armstrong number is a number which is equal to the sum of the digits of the number, raised to the power of the number of digits.

Example 1

Input: n = 153
Output: true
Explanation: Number of digits : 3.
13 + 53 + 33 = 1 + 125 + 27 = 153.
Therefore, it is an Armstrong number.*/

#include <iostream>
#include <cmath>
using namespace std;

bool Armstrong(int n)
{
    int temp = n;
    int length = 0;
    int digit;
    double sum = 0;

    while (temp > 0)
    {
        length += 1;
        temp /= 10;
    }

    temp = n;

    while (temp > 0)
    {
        digit = temp % 10;
        sum = sum + round(pow(digit, length));
        temp /= 10;
    }

    return n == sum;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (Armstrong(n))
    {
        cout << "Yes, it is an Armstrong number.\n";
        return 0;
    }
    else
    {
        cout << "No, it is not an Armstrong number.\n";
        return 0;
    }
}