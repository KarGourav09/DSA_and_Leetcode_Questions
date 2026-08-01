/*486. Predict the Winner, Medium
You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

 

Example 1:

Input: nums = [1,5,2]
Output: false
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return false.
Example 2:

Input: nums = [1,5,233,7]
Output: true
Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 107

Solution: first we will iterate through the entire array we will keep a counter for each iteration and alternate the players, we will keep their scores as they choose the numbers for which we will use a recursion function to keep track of the scores and return the final result. for the option of choosing from the left or right we will find for both and if player win in any of the two options we will return true else false.

time: O(2^n) where n is the number of elements in the array. We are exploring all possible combinations of choices for both players.
space: O(n) where n is the number of elements in the array. The space complexity is due to the recursion stack.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool Helper(vector<int>& nums, int left, int right, int score1, int score2, int counter) {
        
        if (left > right) {
            return score1 >= score2;
        }

        if (counter % 2 == 0) { // Player 1's turn
            return Helper(nums, left + 1, right, score1 + nums[left], score2, counter + 1) ||
                   Helper(nums, left, right - 1, score1 + nums[right], score2, counter + 1);
        } else { // Player 2's turn
            return Helper(nums, left + 1, right, score1, score2 + nums[left], counter + 1) &&
                   Helper(nums, left, right - 1, score1, score2 + nums[right], counter + 1);
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int score1 = 0, score2 = 0;
        int counter = 0;

        return Helper(nums, 0, n - 1, score1, score2, counter);
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 5, 2};
    cout << boolalpha << solution.predictTheWinner(nums1) << endl; // Output: false

    vector<int> nums2 = {1, 5, 233, 7};
    cout << boolalpha << solution.predictTheWinner(nums2) << endl; // Output: true

    return 0;
}