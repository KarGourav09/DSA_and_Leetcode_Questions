/*
A. Cover in Water

Time limit: 1 second
Memory limit: 256 megabytes

Filip has a row of cells. Some cells are blocked, while the others are empty.
He wants every empty cell to contain water. He can perform the following
operations:

1. Place water in an empty cell.
2. Remove water from one cell and place it in any other empty cell.

If an empty cell i (2 <= i <= n - 1) has water in both neighboring cells,
i - 1 and i + 1, it becomes filled with water automatically.

Find the minimum number of times Filip must perform operation 1 to fill all
empty cells with water. The number of operation 2 uses does not need to be
minimized. Blocked cells cannot contain water, and Filip cannot place water
in them.

Input:
The first line contains the number of test cases t (1 <= t <= 100).

For each test case:
- The first line contains an integer n (1 <= n <= 100), the number of cells.
- The second line contains a string s of length n. The i-th character is '.'
  if cell i is empty, and '#' if cell i is blocked.

Output:
For each test case, print the minimum number of operation 1 uses required to
fill all empty cells with water.

Example:
Input:
5
3
...
7
##....#
7
..#.#..
4
####
10
#...#..#.#

Output:
2
2
5
0
2

Explanation:

Test case 1:
Filip can put water in cells 1 and 3. Since cell 2 is between two cells with
water, it becomes filled automatically.

Test case 2:
Filip can put water in cells 3 and 5, which fills cell 4 automatically. He
can then move the water from cell 5 to cell 6. Since cells 4 and 6 contain
water, cell 5 also becomes filled automatically.

Test case 3:
Filip must put water in every empty cell, requiring 5 uses of operation 1.

Test case 4:
There are no empty cells, so no operations are required.

Test case 5:
There is a sequence of operations that requires only 2 uses of operation 1.

Solution: Count the empty cells and track the longest consecutive run of empty
cells. If any run has length at least 3, the answer is 2 because water can be
moved between runs and the remaining cells fill automatically. Otherwise,
every empty cell must be filled directly, so the answer is the total number
of empty cells.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperationsToFillWater(const string& s){
        int emptyCells = 0;
        int longestRun = 0;
        int currentRun = 0;

        for (char cell : s) {
            if (cell == '.') {
                ++emptyCells;
                ++currentRun;
                longestRun = max(longestRun, currentRun);
            } else {
                currentRun = 0;
            }
        }

        return longestRun >= 3 ? 2 : emptyCells;
    }
};

int main() {
    int testCases;
    cin >> testCases;

    Solution solution;
    while (testCases--) {
        int n;
        string s;
        cin >> n >> s;
        cout << solution.minOperationsToFillWater(s) << '\n';
    }

    return 0;
}