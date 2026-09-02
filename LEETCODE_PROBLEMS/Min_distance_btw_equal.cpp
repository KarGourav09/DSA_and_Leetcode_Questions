/*3741. Minimum Distance Between Three Equal Elements II, Medium
You are given an integer array nums.
A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].
The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.
Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

Example 1:
Input: nums = [1,2,1,1,3]
Output: 6
Explanation:
The minimum distance is achieved by the good tuple (0, 2, 3).
(0, 2, 3) is a good tuple because nums[0] == nums[2] == nums[3] == 1. Its distance is abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6.

Example 2:
Input: nums = [1,1,2,3,2,1,2]
Output: 8
Explanation:
The minimum distance is achieved by the good tuple (2, 4, 6).
(2, 4, 6) is a good tuple because nums[2] == nums[4] == nums[6] == 2. Its distance is abs(2 - 4) + abs(4 - 6) + abs(6 - 2) = 2 + 2 + 4 = 8.

Example 3:
Input: nums = [1]
Output: -1
Explanation:
There are no good tuples. Therefore, the answer is -1.

Constraints:

1 <= n == nums.length <= 105
1 <= nums[i] <= n

Best Solution Approach:
To solve this problem, we can use a hash map to store the indices of each number in the array. We will iterate through the array and for each number, we will check if it has appeared at least three times. If it has, we will calculate the distance for all combinations of three indices and keep track of the minimum distance found.
time complexity: O(n^3) in the worst case, where n is the length of the input array nums. This is because we may need to check all combinations of three indices for each number that appears at least three times.
space complexity: O(n), where n is the length of the input array nums. We use a hash map to store the indices of each number, which can take up to O(n) space in the worst case.

optimization:
To optimize the solution, we can reduce the time complexity by only considering the last three occurrences of each number. Instead of checking all combinations of three indices, we can maintain a list of the last three indices for each number and calculate the distance only for those indices. This way, we can reduce the time complexity to O(n) while still ensuring that we find the minimum distance for good tuples.
optimized time complexity: O(n), where n is the length of the input array nums. We iterate through the array once to build the hash map and then check the last three occurrences for each number.
space complexity: O(n), where n is the length of the input array nums. We use a hash map to store the last three indices of each number, which can take up to O(n) space in the worst case.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // Store indices for each number
        unordered_map<int, vector<int>> numIndices;
        
        for (int i = 0; i < nums.size(); i++) {
            numIndices[nums[i]].push_back(i);
        }

        int minDistance = INT_MAX;
        
        // For each number, check only consecutive triplets
        // This is optimal because for i < j < k, distance = 2(k-i)
        // Minimum is achieved by consecutive elements
        for (const auto& pair : numIndices) {
            const vector<int>& indices = pair.second;
            
            if (indices.size() >= 3) {
                // Check all consecutive triplets
                for (int i = 0; i <= (int)indices.size() - 3; i++) {
                    int distance = 2 * (indices[i + 2] - indices[i]);
                    minDistance = min(minDistance, distance);
                }
            }
        }

        return minDistance == INT_MAX ? -1 : minDistance;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 5, 5, 2, 5};
    cout << solution.minimumDistance(nums) << endl; // Output: 4

    nums = {1, 1, 2, 3, 2, 1, 2};
    cout << solution.minimumDistance(nums) << endl; // Output: 8

    nums = {1};
    cout << solution.minimumDistance(nums) << endl; // Output: -1

    return 0;
}