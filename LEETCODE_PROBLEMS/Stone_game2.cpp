/*1140. Stone Game II, Medium
Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

 

Example 1:
Input: piles = [2,7,9,4,4]
Output: 10
Explanation:

If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
So we return 10 since it's larger.

Example 2:
Input: piles = [1,2,3,4,5,100]
Output: 104

 

Constraints:
1 <= piles.length <= 100
1 <= piles[i] <= 104

Solution: We will use dynamic programming to solve this problem. We will create a 2D dp array where dp[i][j] will represent the maximum number of stones Alice can get if she starts at pile i and the current value of M is j. We will also create a prefix sum array to calculate the sum of stones from pile i to the end in O(1) time. The base case will be when we reach the end of the piles, in which case Alice cannot take any more stones. We will iterate through the piles and for each pile, we will try taking X piles where 1 <= X <= 2M and calculate the maximum stones Alice can get by taking those piles and then subtracting the maximum stones Bob can get from the remaining piles. Finally, we will return dp[0][1] which represents the maximum stones Alice can get starting from the first pile with M = 1.

time: O(n^3) where n is the number of piles.
space: O(n^2) where n is the number of piles.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& piles, vector<vector<int>>& dp, vector<int>& prefixSum, int i, int M) {
        if (i >= piles.size()) {
            return 0;
        }
        if (dp[i][M] != -1) {
            return dp[i][M];
        }
        int maxStones = 0;
        for (int X = 1; X <= 2 * M; X++) {
            if (i + X > piles.size()) {
                break;
            }
            int stonesTaken = prefixSum[i + X] - prefixSum[i];
            int stonesLeft = helper(piles, dp, prefixSum, i + X, max(M, X));
            maxStones = max(maxStones, stonesTaken + (prefixSum.back() - prefixSum[i + X] - stonesLeft));
        }
        dp[i][M] = maxStones;
        return maxStones;
    }  

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + piles[i];
        }
        return helper(piles, dp, prefixSum, 0, 1);
    }
};

int main() {
    Solution solution;
    vector<int> piles1 = {2, 7, 9, 4, 4};
    cout << solution.stoneGameII(piles1) << endl; // Output: 10

    vector<int> piles2 = {1, 2, 3, 4, 5, 100};
    cout << solution.stoneGameII(piles2) << endl; // Output: 104

    return 0;
}