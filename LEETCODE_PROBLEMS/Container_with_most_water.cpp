/*11. Container With Most Water, Medium
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

Solution: To fins the container with most water, we can use 2 pointer method an fins the area of the container by calculating the minimum height of the two lines and multiplying it by the distance between them. We can then move the pointer pointing to the shorter line towards the other pointer, as this may lead to a taller line and potentially a larger area. We continue this process until the two pointers meet.

time: O(n) - We only traverse the array once with two pointers.
space: O(1) - We only use a constant amount of space for the pointers and the maximum area variable.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            int current_area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, current_area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};

int main() {
    Solution solution;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max area: " << solution.maxArea(height) << endl; // Output: 49
    return 0;
}