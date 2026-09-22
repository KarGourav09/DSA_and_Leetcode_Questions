/*Find out how many times the array has been rotated
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated.

Pre-requisites: Find minimum in Rotated Sorted Array,  Search in Rotated Sorted Array II & Binary Search algorithm

Examples
Input : arr = [4,5,6,7,0,1,2,3]
Result: 4
Explanation: The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the array has been rotated 4 times.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findRotate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            

            if(nums[mid] > nums[right]) {
                    
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4,5,6,7,0,1,2,3};  // Example input
    int rotateCount = solution.findRotate(nums);
    cout << "Number of times the array has been rotated: " << rotateCount << endl;
    return 0;
}