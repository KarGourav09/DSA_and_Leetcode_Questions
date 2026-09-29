/*907. Sum of Subarray Minimums
Medium
Topics
premium lock icon
Companies
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104

Solution: 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i = arr.size() - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> next = nextSmallerElement(arr);
        vector<int> prev = prevSmallerElement(arr);
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum = (sum + (long long)arr[i] * (i - prev[i]) * (next[i] - i)) % 1000000007;
        }
        return sum;
    }
};




int main() {
    Solution solution;
    vector<int> arr = {3, 1, 2, 4};
    int result = solution.sumSubarrayMins(arr);
    cout << "Sum of subarray minimums: " << result << endl;
    return 0;
}


/*
Brute Force Approach:
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int minVal = arr[i];
            for (int j = i; j < n; j++) {
                minVal = min(minVal, arr[j]);
                sum = (sum + minVal) % 1000000007;
            }
        }
        return sum;
    }
};
*/