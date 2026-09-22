/*229. Majority Element II, Medium
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Constraints:
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109

Follow up: Could you solve the problem in linear time and in O(1) space?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;

        int n = nums.size();
        int limit = n / 3;
        unordered_map<int, int> counts;

        for (int i = 0; i < n; i++) {

            counts[nums[i]]++;

            if (counts[nums[i]] > limit) {
                if (find(result.begin(), result.end(), nums[i]) ==
                    result.end()) {
                    result.push_back(nums[i]);
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 2, 3};
    vector<int> result = s.majorityElement(nums);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*
alternative solution using Boyer-Moore Voting Algorithm:

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> result;
        int n = nums.size();
        int limit = n / 3;

        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 1; // Initialize to different values

        for (int num : nums)
        {
            if (num == candidate1)
            {
                count1++;
            }
            else if (num == candidate2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                candidate2 = num;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        // Verify the candidates
        count1 = count2 = 0;
        for (int num : nums)
        {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        if (count1 > limit) result.push_back(candidate1);
        if (count2 > limit) result.push_back(candidate2);

        return result;
    }
};

*/