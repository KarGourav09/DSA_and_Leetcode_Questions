/*The problem asks for the minimum number of operations to make the product of all elements in an array equal to zero. An operation consists of increasing or decreasing an element's value by 1.

The product of a set of numbers is zero if and only if at least one of the numbers is zero. Therefore, the goal is to make at least one element in the array equal to zero with the minimum number of operations.

Here's a breakdown of the solution:

1.  **Iterate through the array:** Go through each element `A[i]` in the given array.

2.  **Calculate operations for each element:** For each `A[i]`, determine the number of operations needed to make it zero.
    *   If `A[i]` is already 0, no operations are needed for this element (0 operations).
    *   If `A[i]` is positive, say 5, you need to decrease it by 5 to make it 0. This takes 5 operations. In general, for a positive `A[i]`, it takes `A[i]` operations.
    *   If `A[i]` is negative, say -3, you need to increase it by 3 to make it 0. This takes 3 operations. In general, for a negative `A[i]`, it takes `abs(A[i])` operations.
    *   In summary, for any non-zero `A[i]`, it takes `abs(A[i])` operations to make it zero.

3.  **Find the minimum:** The minimum number of operations to make the entire product zero is simply the minimum number of operations required to turn *any* single element into zero. This is because if we make one element zero, the entire product becomes zero, and we want to achieve this with the fewest possible changes.

Therefore, the algorithm is:
*   Initialize `min_operations` to a very large number (or the operations needed for the first element).
*   For each element `x` in the array:
    *   Calculate `current_operations = abs(x)`.
    *   Update `min_operations = min(min_operations, current_operations)`.
*   The final `min_operations` will be the answer.

**Example 1: `[2, -6, 5]`**

*   For `2`: `abs(2) = 2` operations to make it 0.
*   For `-6`: `abs(-6) = 6` operations to make it 0.
*   For `5`: `abs(5) = 5` operations to make it 0.

The minimum of `[2, 6, 5]` is `2`. So, 2 operations are needed (by changing `2` to `0`).

**Example 2: `[-3]`**

*   For `-3`: `abs(-3) = 3` operations to make it 0.

The minimum is `3`. So, 3 operations are needed.

**Example 3: `[0, -1, 0, 1, 0]`**

*   For `0`: `abs(0) = 0` operations to make it 0.
*   For `-1`: `abs(-1) = 1` operation to make it 0.
*   For `0`: `abs(0) = 0` operations to make it 0.
*   For `1`: `abs(1) = 1` operation to make it 0.
*   For `0`: `abs(0) = 0` operations to make it 0.

The minimum of `[0, 1, 0, 1, 0]` is `0`. So, 0 operations are needed.*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int n)
    {
        int min_operations = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            min_operations = min(min_operations, abs(nums[i]));
        }
        return min_operations;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.minOperations(nums, n) << endl;
}