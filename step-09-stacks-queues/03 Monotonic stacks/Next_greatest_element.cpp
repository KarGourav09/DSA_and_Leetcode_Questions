/*496. Next Greater Element I Easy
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
 

Constraints:

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.

Algorithm
Create an answer array of size N1 and initialize every position with -1.
Create an empty monotonic stack to store potential greater elements.
Traverse the array nums2 from index N2 - 1 to 0, because the stack must contain only elements appearing to the right of the current index.

For each current element:
While the stack is not empty and the top of the stack is less than or equal to the current element, pop the top of the stack.
If the stack is not empty, the top of the stack is the next greater element for the current element. 
Store this value in a hash map with the current element as the key.
Push the current element onto the stack.
Finally, iterate through nums1 and use the hash map to find the next greater element for each element.

time complexity: O(N2) where N2 is the length of nums2. Each element is pushed and popped from the stack at most once.
space complexity: O(N2) for the stack and the hash map.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nextGreater;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            nextGreater[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        vector<int> ans;
        for (int value : nums1) {
            ans.push_back(nextGreater[value]);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = solution.nextGreaterElement(nums1, nums2); // Output: [-1, 3, -1]

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}