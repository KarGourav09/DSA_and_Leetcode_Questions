/*1980. Find Unique Binary String, Medium
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.


Example 1:
Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.

Example 2:
Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.

Example 3:
Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.

Solution: We can use a set to store all the binary strings in the input array. Then, we can generate all possible binary strings of length n and check if they are present in the set. If we find a binary string that is not present in the set, we return it as the answer.

time: O(2^n) where n is the length of the binary strings. We are generating all possible binary strings of length n.
space: O(n) where n is the length of the binary strings. The space complexity is due to the set used to store the binary strings.

Optimisation: We can use a more efficient approach by using the fact that there are 2^n possible binary strings of length n. Since the input array contains n unique binary strings, there must be at least one binary string of length n that is not present in the input array. We can generate a binary string by flipping the bits of the binary strings in the input array. For example, if the input array contains "01", we can generate "10" by flipping the bits. This way, we can guarantee that the generated binary string is not present in the input array.

new time: O(n) where n is the length of the binary strings. We are generating a binary string by flipping the bits of the binary strings in the input array.
new space: O(n) where n is the length of the binary strings. The space complexity is due to the set used to store the binary strings.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = "";

        for (int i = 0; i < n; i++) {
            result += (nums[i][i] == '0') ? '1' : '0';
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<string> nums = {"01", "10"};
    string result = solution.findDifferentBinaryString(nums);
    cout << "Output: " << result << endl; // Output: "11"
    return 0;
}