/*1838. Frequency of the Most Frequent Element, Medium
Hint
The frequency of an element is the number of times it occurs in an array.
You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.
Return the maximum possible frequency of an element after performing at most k operations.
 
Example 1:
Input: nums = [1,2,4], k = 5 Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.

Solution: Sliding Window
1. Sort the array to group closer numbers together.
2. Use two pointers (left and right) to create a sliding window. Expand the right pointer to include more elements and calculate the total sum of the current window.
3. If the operations needed to make all elements in the window equal to the rightmost element exceeds k, shrink the window from the left until it is valid again.
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        // Step 1: Sort the array to group closer numbers together
        sort(nums.begin(), nums.end());

        long long int l = 0, r = 0, total_sum = 0, n = nums.size(); // Use long long to prevent integer overflow
        long long int max_freq = 0;

        // Step 2: Expand the window with the right pointer and calculate the total sum of the current window
        for (r = 0; r < n; r++)
        {
            total_sum += nums[r];

            // Calculate operations needed: (window_len * target) - actual_sum
            // If it exceeds k, shrink the window from the left
            while (l+1 <= r && nums[r] * (r - l + 1) > total_sum + k)
            {
                total_sum -= nums[l];
                l++;
            }

            // Step 3: Update the maximum frequency found so far
            max_freq = max(max_freq, r - l + 1);
        }

        return max_freq;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 4};
    int k = 5; 
    cout << "Maximum Frequency: " << sol.maxFrequency(nums, k) << endl; // Output: 3
    return 0;
}