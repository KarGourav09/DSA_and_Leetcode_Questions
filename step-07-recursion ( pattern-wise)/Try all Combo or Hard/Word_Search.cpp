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

Solution: 1. First we will take the first character of the word and search for it in the board. If we find it, we will start a DFS from that cell to find the next character of the word. We will mark the cell as visited by changing its value to a special character (e.g., '#') and then backtrack after exploring all possible paths. If we reach the end of the word, we return true. If we exhaust all possibilities and do not find the word, we return false.

time: O(N * 3^L) where N is the number of cells in the board and L is the length of the word. In the worst case, we may have to explore all 3 directions (up, down, left, right) for each character in the word.
Space: O(L) where L is the length of the word. The space complexity is determined by the recursion stack, which can go as deep as the length of the word in the worst case.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        int len = word.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (k == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) return false;
        char temp = board[i][j];
        board[i][j] = '#'; // Mark as visited
        bool found = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) || dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = temp; // Backtrack
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