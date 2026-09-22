/*1539. Kth Missing Positive Number, Easy
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;

        for(int i = 1; i <= arr.size() + k; i++) {
            if(find(arr.begin(), arr.end(), i) == arr.end()) {
                missing.push_back(i);
            }
        }
        return missing[k - 1];
    }
};
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int missingCount = arr[mid] - (mid + 1); // Technique to find the nth missing index in that particular position in the array.

            if(missingCount < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low + k;
    }
};


int main() {
    Solution solution;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    int result = solution.findKthPositive(arr, k);
    cout << "The " << k << "th missing positive integer is: " << result << endl; // Output: 9
    return 0;
}

/*
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;

        for(int i = 1; i <= arr.size() + k; i++) {
            for(int j = 0; j < arr.size(); j++) {
                if(arr[j] == i) {
                    break;
                }
                if(j == arr.size() - 1) {
                    missing.push_back(i);
                }
            }
        }
        return missing[k - 1];
    }
};
*/