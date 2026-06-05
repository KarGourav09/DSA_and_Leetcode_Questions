/*121. Best Time to Buy and Sell Stock, Easy
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Solution: We can use the Sliding Window Template to solve this problem. We will maintain two pointers, one for the buying day and one for the selling day. We will iterate through the prices array and update the minimum price and maximum profit accordingly.
We must ensure that the selling day is always after the buying day, so we will only update the selling day pointer when we find a price that is greater than the minimum price. This way, we can guarantee that we are always selling after buying.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0; // Can't make a transaction with less than 2 days

        int l = 0; // Left pointer = Buying day
        int max_profit = 0;

        // Right pointer = Selling day
        for (int r = 1; r < n; r++) {
            // If profitable, track the profit
            if (prices[r] > prices[l]) {
                int current_profit = prices[r] - prices[l];
                max_profit = max(max_profit, current_profit);
            } 
            // If the price dropped below our buying point, update our buying day
            else {
                l = r;
            }
        }

        return max_profit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    Solution solution;
    cout << "Max Profit: " << solution.maxProfit(prices) << endl; // Output: 5

    return 0;
}