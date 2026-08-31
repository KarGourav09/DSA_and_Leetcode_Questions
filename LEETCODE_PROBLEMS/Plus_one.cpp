/*66. Plus One, Easy
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.

Solution: We will iterate through the digits array from the last index to the first index. If we find a digit less than 9, we will increment it by 1 and return the array. If we find a digit equal to 9, we will set it to 0 and continue to the next digit. If we reach the first index and all digits are 9, we will create a new array with size n+1, set the first element to 1 and return the new array.
Time Complexity: O(n) where n is the number of digits in the array.
Space Complexity: O(1) if we don't consider the space used for the output array, otherwise O(n) for the output array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution solution;
    vector<int> digits = {9, 9, 9};
    vector<int> result = solution.plusOne(digits);
    cout << "Result: ";
    for (int digit : result) {
        cout << digit << " ";
    }
    cout << endl;
    return 0;
}