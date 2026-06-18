/*Nth Root of a Number using Binary Search
Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

Examples
Input: N = 3, M = 27
Output: 3
Explanation: The cube root of 27 is equal to 3.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int NthRoot(int N, int M){
        int low = 1, high = M, ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long power = pow(mid, N); // Calculate mid^N
            if(power == M){
                return mid; // Perfect root case
            }
            else if(power < M){
                ans = mid; // Store the potential root
                low = mid + 1; // Search in the right half
            }
            else{
                high = mid - 1; // Search in the left half
            }
        }
        return ans; // Return the nth root or -1 if not found
    }
};

int main() {
    Solution solution;
    int N = 3, M = 27;
    int result = solution.NthRoot(N, M);
    cout << "The " << N << "rd root of " << M << " is: " << result << endl; // Output: 3
    return 0;
}

/*
Solution: Brute Force Approach
The simplest way to find the nth root of a number is to iterate from 1 to M and check if the current number raised to the power N is equal to M. If it is, we return that number. If we exceed M, we return -1.

class Solution {
public:
    int NthRoot(int N, int M){
        for(int i = 1; i <= M; i++){
            if(pow(i, N) == M){
                return i; // Perfect root case
            }
        }
        return -1; // Return -1 if nth root is not an integer
    }
};
*/