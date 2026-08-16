/*Find the two numbers appearing odd number of times
Problem Statement: Given an array nums of length n, every integer in the array appears twice except for two integers. Identify and return the two integers that appear only once in the array. Return the two numbers in ascending order.
For example, if nums = [1, 2, 1, 3, 5, 2], the correct answer is [3, 5], not [5, 3].

Example 1:
Input:
 nums = [1, 2, 1, 3, 5, 2]
Output:
 [3, 5]
Explanation:
The integers 3 and 5 have appeared only once.

Example 2:
Input:
 nums = [-1, 0]
Output:
 [-1, 0]
Explanation:
The integers -1 and 0 have appeared only once.

Solution: We will use XOR operation to find the two unique numbers. First, we will XOR all the numbers in the array to get the XOR of the two unique numbers. Then, we will find a set bit in the result (which indicates that the two unique numbers differ at that bit position). We will use this set bit to partition the array into two groups and XOR each group separately to find the two unique numbers.
Time Complexity: O(n), where n is the length of the array.
Space Complexity: O(1), as we are using a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public: 
   vector<int> FindTwoUniqueNums(vector<int> nums){
    int n = nums.size();
    int xor_result = 0;
    for(int i = 0; i < n; i++){
        xor_result ^= nums[i];
    }

    // Find a set bit in xor_result
    int set_bit = xor_result & -xor_result; // Get the rightmost set bit
    int num1 = 0, num2 = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] & set_bit){
            num1 ^= nums[i];
        }
        else{
            num2 ^= nums[i];
        }
    }
    return {min(num1, num2), max(num1, num2)};
   }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 5, 2};
    vector<int> result = sol.FindTwoUniqueNums(nums);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl; // Output: [3, 5]
    return 0;
}