/*Aggressive Cows : Detailed Solution
Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls. You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible. Find the maximum possible minimum distance.

Examples
Example 1:
Input Format:
 N = 6, k = 4, arr[] = {0,3,4,7,10,9}
Result:
 3
Explanation:
 The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int canPlaceCows(vector<int>& arr, int k, int minDist) {
        int count = 1; // Place the first cow in the first stall
        int lastPosition = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastPosition >= minDist) {
                count++; // Place another cow
                lastPosition = arr[i]; // Update the last position
            }
            if (count == k) {
                return true; // All cows have been placed successfully
            }
        }
        return false; // Not all cows could be placed with the given minimum distance
    }


    int aggressiveCows(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int low = 1, high = arr.back() - arr.front();
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlaceCows(arr, k, mid)) {
                result = mid; // Update result if we can place cows with this distance
                low = mid + 1; // Try for a larger distance
            } else {
                high = mid - 1; // Try for a smaller distance
            }
        }
        return result;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution solution;
    int maxMinDistance = solution.aggressiveCows(arr, k);
    cout << maxMinDistance << endl;

    return 0;
}