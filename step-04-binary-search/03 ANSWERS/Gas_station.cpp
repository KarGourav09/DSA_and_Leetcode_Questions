/*Minimise Maximum Distance between Gas Stations

Problem Statement: You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis. You are also given an integer ‘k’. You have to place 'k' new gas stations on the X-axis. You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions. Let 'dist' be the maximum value of the distance between adjacent gas stations after adding k new gas stations. Find the minimum value of ‘dist’.

Example 1:
Input Format: N = 5, arr[] = {1,2,3,4,5}, k = 4
Result: 0.5
Explanation: One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}. Thus the maximum difference between adjacent gas stations is 0.5. Hence, the value of ‘dist’ is 0.5. It can be shown that there is no possible way to add 4 gas stations in such a way that the value of ‘dist’ is lower than this. 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countGasStations(const vector<int>& arr, long double dist) {
        int count = 0;
        for (int i = 1; i < arr.size(); ++i) {
            long double gap = arr[i] - arr[i - 1];
            count += static_cast<int>(gap / dist);
        }
        return count;
    }

    long double minmaxGasDist(vector<int>& arr, int k) {
        long double low = 0.0;
        long double high = 0;

        for (int i = 1; i < arr.size(); ++i) {
            high = max(high, static_cast<long double>(arr[i] - arr[i - 1]));
        }

        long double mid;


        while (high - low > 1e-6) {
            mid = low + (high - low) / 2.0;
            if (countGasStations(arr, mid) > k) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    cout << solution.minmaxGasDist(arr, k) << endl; // Output: 0.5
    return 0;
}