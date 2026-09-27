/*503. Next Greater Element II, Medium
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
 

Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109

Solution: We will keep a stack with all the elements in decreasing order. We will traverse the array and for each element, we will top ( see the top element) then traverse the stack to find its next greatest, if found we will store it in the answer array, else -1 is stored. We will traverse the array twice to handle the circular nature of the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(), -1);

        for(int i = 0; i < 2 * nums.size(); i++) {
            while (!st.empty() && nums[st.top()] < nums[i % nums.size()]) {
                ans[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            if (i < nums.size()) {
                st.push(i);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 1};
    vector<int> result = solution.nextGreaterElements(nums); // Output: [2, -1, 2]
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}