/*36. Valid Sudoku, Medium
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.

Solution: We will use 3 functions, one main function to check the validity of the Sudoku board, another function which will check all the rows and columns and find if there is any duplicate number in that row or column, and at the end of this function if no duplicate found then start another function which will check all the 3x3 sub-boxes and find if there is any duplicate number in that sub-box. If no duplicate found then return true else return false.

time: O(n^2) where n is the number of rows or columns in the Sudoku board. Since the board is always 9x9, this is effectively O(1) in practice.
Space: O(n^2) where n is the number of rows or columns in the Sudoku board. Since the board is always 9x9, this is effectively O(1) in practice.

Optimization: We can optimize the space complexity by using bit manipulation instead of unordered_set to track the numbers seen in each row, column, and sub-box. This would reduce the space usage from O(n^2) to O(1) since we only need a fixed number of bits to represent the digits 1-9.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool CheckSubBoxes(vector<vector<char>>& board) {
        for (int boxRow = 0; boxRow < 3; boxRow++){
            for (int boxCol = 0; boxCol < 3; boxCol++){
                int seen = 0;
                for (int i = 0; i < 3; i++){
                    for (int j = 0; j < 3; j++){
                        char current = board[boxRow * 3 + i][boxCol * 3 + j];
                        if (current != '.'){
                            int num = current - '1';
                            if (seen & (1 << num)){
                                return false;
                            }
                            seen |= (1 << num);
                        }
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows and columns for duplicates
        for (int i = 0; i < 9; i++){
            int seenRow = 0; // Bitmask for row
            int seenCol = 0; // Bitmask for column
            for (int j = 0; j < 9; j++){
                // Check row
                char currentRow = board[i][j];
                if (currentRow != '.'){
                    int numRow = currentRow - '1'; // Convert char to index (0-8)
                    if (seenRow & (1 << numRow)){ // Check if the number has been seen in the row
                        return false;
                    }
                    seenRow |= (1 << numRow); // Mark the number as seen in the row
                }

                // Check column
                char currentCol = board[j][i];
                if (currentCol != '.'){
                    int numCol = currentCol - '1'; // Convert char to index (0-8)
                    if (seenCol & (1 << numCol)){ // Check if the number has been seen in the column
                        return false;
                    }
                    seenCol |= (1 << numCol); // Mark the number as seen in the column
                }
            }
        }

        // Check 3x3 sub-boxes for duplicates
        return CheckSubBoxes(board);
    }
};

int main() {
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
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    bool isValid = solution.isValidSudoku(board);
    cout << (isValid ? "true" : "false") << endl;
    return 0;
}