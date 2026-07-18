/*Rat in a Maze
Problem Statement: Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1). Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right).
The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any other cell.

Examples
Input: n = 4 , grid = [ [1, 0, 0, 0] , [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1] ]
Output: ["DDRDRR" , "DRDDRR"]
Explanation: The rat has two different path to reach (3, 3).
The first path is (0, 0) => (1, 0) => (2, 0) => (2, 1) => (3, 1) => (3, 2) => (3, 3).
The second path is (0,0) => (1,0) => (1,1) => (2,1) => (3,1) => (3,2) => (3,3).

Input: n = 2 , grid = [[1, 0] , [1, 0]]
Output: []
Explanation: There is no path that rat can choose to travel from (0,0) to (1,1).

Solution Approach: We can use backtracking to find all possible paths from (0, 0) to (n-1, n-1).
We will maintain a visited matrix to keep track of the cells that have already been visited in the current path.
At each cell, we will explore all four possible directions (up, down, left, right) and recursively call the function for the next cell if it is safe to move there.
If we reach the destination cell (n-1, n-1), we will add the current path to the result list. After exploring all possible paths from a cell, we will backtrack by marking the cell as unvisited.

time: O(4^(n^2)) - In the worst case, we can explore all four directions from each cell, leading to an exponential number of paths.
space: O(n^2) - We use a visited matrix of size n x n to keep track of visited cells, and the recursion stack can go up to n^2 in the worst case.

Optimization: We can optimize the solution by using a single string to keep track of the current path instead of using a separate visited matrix.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int i, int j, vector<vector<int>> &maze, int n, string path, vector<string> &result)
    {
        if (i == n - 1 && j == n - 1)
        {
            result.push_back(path);
            return;
        }

        maze[i][j] = 0;

        // Down
        if (i + 1 < n && maze[i + 1][j] == 1)
            solve(i + 1, j, maze, n, path + 'D', result);

        // Left
        if (j - 1 >= 0 && maze[i][j - 1] == 1)
            solve(i, j - 1, maze, n, path + 'L', result);

        // Right
        if (j + 1 < n && maze[i][j + 1] == 1)
            solve(i, j + 1, maze, n, path + 'R', result);

        // Up
        if (i - 1 >= 0 && maze[i - 1][j] == 1)
            solve(i - 1, j, maze, n, path + 'U', result);

        maze[i][j] = 1; // Backtrack
    }

    vector<string> RatInMaze(vector<vector<int>> &maze, int n)
    {
        vector<string> result;
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return result;

        solve(0, 0, maze, n, "", result);
        return result;
    }
};

int main()
{
    int n = 4;
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    Solution obj;
    vector<string> result = obj.RatInMaze(maze, n);

    if (result.empty())
    {
        cout << "[]" << endl;
    }
    else
    {
        cout << "[";
        for (size_t i = 0; i < result.size(); i++)
        {
            cout << "\"" << result[i] << "\"";
            if (i != result.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}