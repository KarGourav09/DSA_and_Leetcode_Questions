/*53. Maximum Subarray, Medium
integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Solution: We can use Kadane's algorithm to solve this problem efficiently. The idea is to iterate through the array and keep track of the maximum sum of the subarray that ends at the current index. We also keep track of the overall maximum sum found so far.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &arr)
    {
        if (arr.empty())
            return 0;

        int max_sum = arr[0];
        int current_sum = arr[0];

        for (size_t i = 1; i < arr.size(); i++)
        {

            current_sum = max(arr[i], current_sum + arr[i]);

            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution solution;
    int result = solution.maxSubArray(arr);
    cout << "The maximum sum of the subarray is: " << result << endl;

    return 0;
}