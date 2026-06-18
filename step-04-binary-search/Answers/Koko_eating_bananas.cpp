/*875. Koko Eating Bananas, Medium
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 
Constraints:
1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), ans = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long hours = 0;
            for(int pile : piles){
                hours += (pile + mid - 1) / mid; // Calculate hours needed for this pile
            }
            if(hours <= h){
                ans = mid; // Update the minimum speed
                high = mid - 1; // Try to find a smaller speed
            }
            else{
                low = mid + 1; // Increase the speed
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    int result = solution.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl; // Output: 4
    return 0;
}