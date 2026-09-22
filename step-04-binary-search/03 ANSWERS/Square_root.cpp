/*Finding Sqrt of a number using Binary Search
Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

Examples
Input: N = 36
Output: 6
Explanation: Square root of 36 is 6.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int SquareRoot(int n){
        int low = 0, high = n, ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(mid * mid == n){
                return mid; // Perfect square case
            }
            else if(mid * mid < n){
                ans = mid; // Store the floor value
                low = mid + 1; // Search in the right half
            }
            else{
                high = mid - 1; // Search in the left half
            }
        }
        return ans; // Return the floor value of sqrt(n)
    }
};

int main() {
    Solution solution;
    int n = 36;
    int result = solution.SquareRoot(n);
    cout << "Square root of " << n << " is: " << result << endl; // Output: 6
    return 0;
}

/*
Solution: Brute Force Approach
The simplest way to find the square root of a number is to iterate from 1 to n and check if the square of the current number is equal to n. If it is, we return that number. If we exceed n, we return the last number that was less than n.

class Solution {
public:
    int SquareRoot(int n){
        for(int i = 1; i * i <= n; i++){
            if(i * i == n){
                return i; // Perfect square case
            }
        }
        return ans; // Return the floor value of sqrt(n)
    }
};*/