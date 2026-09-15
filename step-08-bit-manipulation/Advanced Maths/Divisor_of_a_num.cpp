/*Print all Divisors of a given Number

Problem Statement: Given an integer N, return all divisors of N.
A divisor of an integer N is a positive integer that divides N without leaving a remainder. In other words, if N is divisible by another integer without any remainder, then that integer is considered a divisor of N.

Examples
Input: N = 36
Output: [1, 2, 3, 4, 6, 9, 12, 18, 36]  
Explanation: The divisors of 36 are 1, 2, 3, 4, 6, 9, 12, 18, 36.
Input: N = 12
Output: [1, 2, 3, 4, 6, 12]
Explanation: The divisors of 12 are 1, 2, 3, 4, 6, 12.

Solution: We will iterate from 1 to the square root of N. For each integer i in this range, if N is divisible by i (i.e., N % i == 0), then both i and N/i are divisors of N. We will store these divisors in a set to avoid duplicates and then return the sorted list of divisors.
Time Complexity: O(sqrt(N)), where N is the given integer.
Space Complexity: O(k), where k is the number of divisors of N, as we are storing the divisors in a set.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> FindDivisor(vector<int> nums){
        int N = nums[0]; // Assuming the input is a vector with a single integer N
        set<int> divisors;
        for(int i = 1; i <= sqrt(N); i++){
            if(N % i == 0){
                divisors.insert(i);
                divisors.insert(N / i);
            }
        }
        return vector<int>(divisors.begin(), divisors.end());
    }
};

int main(){
    Solution sol;
    vector<int> nums = {36}; // Example input
    vector<int> result = sol.FindDivisor(nums);
    cout << "[";
    for(size_t i = 0; i < result.size(); i++){
        cout << result[i];
        if(i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl; // Output: [1, 2, 3, 4, 6, 9, 12, 18, 36]
    return 0;
}