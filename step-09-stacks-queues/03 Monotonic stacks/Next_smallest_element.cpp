/*194. Next Smaller Element
Given an array of integers arr, your task is to find the Next Smaller Element (NSE) for every element in the array.

The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.

If there is no smaller element to the right, then the NSE is -1.

Example 1:
Input: arr = [4, 8, 5, 2, 25]

Output: [2, 5, 2, -1, -1]

Explanation:

- For 4, the next smaller element is 2.

- For 8, the next smaller element is 5.

- For 5, the next smaller element is 2.

- For 2, there is no smaller element to its right → -1.

- For 25, no smaller element exists → -1.

Example 2:
Input: arr = [10, 9, 8, 7]

Output: [9, 8, 7, -1]

Explanation:

Each element’s next right neighbor is smaller.

Solution: 
1.Correctness & Approach
verdict: The code scans from right to left and maintains a stack of indices whose values are increasing from top to bottom. Before processing each element, it removes values greater than or equal to the current value; those values cannot be the first strictly smaller element to its right. The remaining top, if present, is the next smaller value. Each index is pushed and popped at most once, making this approach optimal in time.

approach: This is the optimal approach: every element is processed in O(1) amortized time using a monotonic stack.


2.
Time Complexity
O(n). Although an iteration may pop multiple indices, each index is pushed once and popped at most once, so the total number of stack operations is linear.


3.
Space Complexity
O(n) auxiliary space in the worst case for the stack. The returned answer also uses O(n) space.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ans[i] = st.empty() ? -1 : arr[st.top()];
            st.push(i);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> result = sol.nextSmallerElements(arr);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
