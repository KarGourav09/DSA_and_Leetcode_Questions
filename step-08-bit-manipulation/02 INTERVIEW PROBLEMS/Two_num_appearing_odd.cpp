/*Find the two numbers appearing odd number of times
Problem Statement: Given an array nums of length n, every integer in the array appears twice except for two integers. Identify and return the two integers that appear only once in the array. Return the two numbers in ascending order.

For example, if nums = [1, 2, 1, 3, 5, 2], the correct answer is [3, 5], not [5, 3].

Examples
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

Solution: we can solve this problem using bit manipulation, first sort them and check the ith and the i+th element,if the XOR of them is not zero then we can say that they are the two numbers which are appearing odd number of times.

Optimization: we can solve this problem in O(n) time complexity and O(1) space complexity using bit manipulation. We can find the XOR of all the elements in the array, which will give us the XOR of the two numbers that appear only once. Then we can find a set bit in the XOR result, which will help us to divide the numbers into two groups. Finally, we can find the two numbers by XORing the elements in each group.

time: O(n)
space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findTwoNumberAppearingOdd(vector<int>& nums){
        int xorResult = 0;
        for (int num : nums) {
            xorResult ^= num;
        }
        int setBit = xorResult & -xorResult; // Get the rightmost set bit
        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if (num & setBit) {
                num1 ^= num; // Group 1
            } else {
                num2 ^= num; // Group 2
            }
        }
        vector<int> result = {num1, num2};
        sort(result.begin(), result.end()); // Sort the result in ascending order
        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 2};
    Solution sol;
    vector<int> result = sol.findTwoNumberAppearingOdd(nums);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl; // Output: [3, 5]
    return 0;
}