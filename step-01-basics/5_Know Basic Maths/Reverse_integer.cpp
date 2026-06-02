/*Reverse Integer
Medium

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes 
the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 Example 1:
 Input: x = 123
 Output: 321
 Example 2:

 Constraints:
 -231 <= x <= 231

 solution:- make a variable to store the reversed number and initialize it to 0. 
Then, we can use a while loop to extract the last digit of the input number x and 
add it to the reversed number. We also need to check for overflow and underflow conditions 
before adding the digit to the reversed number. Finally, we return the reversed number.*/

#include <iostream>
#include <limits>

using namespace std;

int Reverse(int x)
{
    int rev = 0;
    while (x != 0) {
        int digit = x % 10;
        x /= 10;
        rev = rev * 10 + digit;
        
        // Check for overflow before multiplying
        if (rev > 214748364 || (rev == 214748364 && digit > 7)) return 0;
        if (rev < -214748364 || (rev == -214748364 && digit < -8)) return 0;
    }
    return rev;
}

int main()
{
    int x;
    cin >> x;
    cout << Reverse(x) << endl;
    return 0;
}