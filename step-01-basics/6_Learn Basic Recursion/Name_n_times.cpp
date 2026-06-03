/*Print Name N times using Recursion
Problem Description: Given an integer N, write a program to print your name N times.

Examples
Input: N = 3
Output: Ashish Ashish Ashish 
Explanation: Name is printed 3 times.
Input: N = 1
Output: Ashish 
Explanation: Name is printed once.*/


#include <iostream>
#include <string>
using namespace std;

void RepeatName(int N) {
    if (N <= 0) {
        return; // Base case: if N is 0 or negative, stop recursion
    }
    cout << "Ashish "; // Print the name
    RepeatName(N - 1); // Recursive call with N decremented by 1
}

int main ()
{
    int n;
    string name = "Ashish";
    cout << "Enter the number of times to print the name: ";
    cin >> n;
    RepeatName(n);
    return 0;
}