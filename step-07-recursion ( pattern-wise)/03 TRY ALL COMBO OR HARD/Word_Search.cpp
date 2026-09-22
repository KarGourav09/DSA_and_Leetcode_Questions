/*79. Word Search, Medium
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?

Solution: We can solve this using backtracking. Starting from each cell in the grid, we explore all four possible directions (up, down, left, right) to try to match the next character in the word. We mark visited cells temporarily to avoid reusing them, and backtrack when a path fails. This ensures we explore all possible connected sequences of characters in the board that might form the target word.
        Iterate through each cell in the board.
        If the cell matches the first letter of the word, start a DFS search from that cell.
        In DFS, check boundary conditions and whether the character matches the current letter in the word.
        If matched, temporarily mark the cell as visited.
        Recursively search in all four directions for the next letter.
        If the whole word is found, return true.
        Backtrack by restoring the cell’s original value before returning.
        If no path matches the word, return false.

time: O(N * 3^L), where N is the number of cells in the board and L is the length of the word. Each cell can lead to 3 possible directions (excluding the direction we came from) for each character in the word.
space: O(L), where L is the length of the word, due to the recursion stack

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if (index == word.size()) return true; // All characters matched
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false; // Out of bounds or character mismatch
        }
        
        char temp = board[i][j]; // Store the current character
        board[i][j] = '#'; // Mark as visited
        
        // Explore all four directions
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);
        
        board[i][j] = temp; // Restore the original character
        return found;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    bool result = sol.exist(board, word);
    
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}