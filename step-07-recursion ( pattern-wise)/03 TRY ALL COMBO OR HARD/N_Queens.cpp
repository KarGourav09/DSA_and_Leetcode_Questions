/*51. N-Queens, Hard
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:
1 <= n <= 9

Solution: First lets use brute force, we know that to place n queens in a nxn board, if we consider it as a 2D matrix, and iterate through them, lets take first position (0,0) then we can find the remaining possible positions we can put the remaining queens, similarly we can go to next position and do the same, if we reach the end of the board but we have not placed all the queens, then we can backtrack and try the next position, and so on. This way we can find all the possible combinations of placing n queens in a nxn board.
Optimization: We can optimize the above solution by using 3 arrays to keep track of the columns and diagonals that are already occupied by queens. This way we can avoid checking the entire board for each queen placement, reducing the time complexity.

time: O(n!)
space: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        backtrack(result, board, cols, diag1, diag2, 0, n);
        return result;
    }

private:
    void backtrack(vector<vector<string>>& result, vector<string>& board, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!cols[col] && !diag1[row - col + n - 1] && !diag2[row + col]) {
                board[row][col] = 'Q';
                cols[col] = true;
                diag1[row - col + n - 1] = true;
                diag2[row + col] = true;

                backtrack(result, board, cols, diag1, diag2, row + 1, n);

                board[row][col] = '.';
                cols[col] = false;
                diag1[row - col + n - 1] = false;
                diag2[row + col] = false;
            }
        }
    }
};

int main() {
    Solution solution;
    int n = 4;
    vector<vector<string>> solutions = solution.solveNQueens(n);

    for (const auto& board : solutions) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}