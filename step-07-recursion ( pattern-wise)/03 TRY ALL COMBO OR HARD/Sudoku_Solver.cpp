/*37. Sudoku Solver, Hard
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.



Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution

Solution: We will use a recursive function which will place numbers in all the rows and columns and each time we place a number we will check if the number is valid or not, if it is valid then we will move to the next cell and if it is not valid then we will backtrack and try the next number. If we reach the end of the board then we have found a solution and we will return true.

time: O(9^(n^2)) where n is the number of rows or columns in the Sudoku board. Since the board is always 9x9, this is effectively O(1) in practice.
Space: O(n^2) where n is the number of rows or columns in the Sudoku board. Since the board is always 9x9, this is effectively O(1) in practice.

Optimisation: We can optimize the space complexity by using bit manipulation instead of unordered_set to track the numbers seen in each row, column, and sub-box.
This would reduce the space usage from O(n^2) to O(1) since we only need a fixed number of bits to represent the digits 1-9.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool CheckValid(vector<vector<char>> &board, int row, int col, char num)
    {
        // Check row
        for (int j = 0; j < 9; j++)
        {
            if (board[row][j] == num)
            {
                return false;
            }
        }

        // Check column
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == num)
            {
                return false;
            }
        }

        // Check 3x3 sub-box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++)
        {
            for (int j = startCol; j < startCol + 3; j++)
            {
                if (board[i][j] == num)
                {
                    return false;
                }
            }
        }

        return true; // No conflicts, the number can be placed
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                    for (char num = '1'; num <= '9'; num++)
                    {
                        if (CheckValid(board, row, col, num))
                        {
                            board[row][col] = num;
                            if (solve(board))
                            {
                                return true;
                            }
                            board[row][col] = '.';
                        }
                    }
                    return false; // No valid number found, backtrack
                }
            }
        }
        return true; // All cells filled, solution found
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solution.solveSudoku(board);

    // Print the solved Sudoku board
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}