/*3731. Find Missing Elements, Easy
You are given an integer array nums consisting of unique integers.

Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.

The smallest and largest integers of the original range are still present in nums.

Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.

 

Example 1:
Input: nums = [1,4,2,5]
Output: [3]

Explanation:

The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. Among these, only 3 is missing.

Example 2:
Input: nums = [7,8,6,9]
Output: []

Explanation:

The smallest integer is 6 and the largest is 9, so the full range is [6,7,8,9]. All integers are already present, so no integer is missing.

Example 3:
Input: nums = [5,1]
Output: [2,3,4]

Explanation:

The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. The missing integers are 2, 3, and 4.

 

Constraints:

2 <= nums.length <= 100
1 <= nums[i] <= 100

Solution: First Sort the given array then starting from the first element of the array till the last element of the array we will check if the next element is equal to the current element + 1 or not. If it is not equal then we will add all the elements from current element + 1 to next element - 1 in the answer vector.

time: O(nlogn)
space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> missingElements;
        for (int i = 0; i < nums.size() - 1; i++) {
            int current = nums[i];
            int next = nums[i + 1];
            for (int j = current + 1; j < next; j++) {
                missingElements.push_back(j);
            }
        }
        return missingElements;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 4, 2, 5};
    vector<int> missingElements = solution.findMissingElements(nums);
    cout << "Missing elements: ";
    for (int num : missingElements) {
        cout << num << " ";
    }
    cout << endl;

    nums = {7, 8, 6, 9};
    missingElements = solution.findMissingElements(nums);
    cout << "Missing elements: ";
    for (int num : missingElements) {
        cout << num << " ";
    }
    cout << endl;

    nums = {5, 1};
    missingElements = solution.findMissingElements(nums);
    cout << "Missing elements: ";
    for (int num : missingElements) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}