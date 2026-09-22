/*128. Longest Consecutive Sequence, Medium
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Edge case: an empty array has a sequence length of 0
        if (nums.empty()) return 0;

        // Sort the array - O(n log n)
        sort(nums.begin(), nums.end());

        int longest = 1;      // Global maximum sequence found
        int currentStreak = 1; // Current consecutive sequence tracking

        for (int i = 1; i < nums.size(); i++) {
            // Case 1: Duplicate element. Just skip it, it doesn't break the streak.
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Case 2: Consecutive element. Extend the current streak.
            if (nums[i] == nums[i - 1] + 1) {
                currentStreak++;
            } 
            // Case 3: Broken sequence. Save the max and reset the streak.
            else {
                longest = max(longest, currentStreak);
                currentStreak = 1;
            }
        }

        // Final check in case the longest sequence runs all the way to the end of the array
        return max(longest, currentStreak);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(nums) << endl; // Output: 4
    return 0;
}

/*Alternative approach using unordered_set

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Step 1: Put everything in a hash set - O(n) time and space
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        // Step 2: Look for the start of sequences
        for (int num : nums) {
            // If (num - 1) is NOT in the set, then 'num' is the START of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Expand the streak forward
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                // Update global maximum
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
*/