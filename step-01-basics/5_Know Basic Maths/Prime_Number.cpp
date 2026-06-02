/*Check if a number is prime or not
Problem Statement: Given an integer N, check whether it is prime or not. A prime number is a number that is only divisible by 1 and itself and the total number of divisors is 2..

Example 1:
Input:N = 2        
Output:True            
Explanation: 2 is a prime number because it has two divisors: 1 and 2 (the number itself).*/

#include <iostream>
#include <cmath>
using namespace std;

bool PrimeNum (int n)
{
    if (n <= 1)
        return false;

    for(int i = 2; i <= sqrt(n); i++){
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (PrimeNum(n))
        cout << n << " is a prime number." << endl;
    else
        cout << n << " is not a prime number." << endl;
}