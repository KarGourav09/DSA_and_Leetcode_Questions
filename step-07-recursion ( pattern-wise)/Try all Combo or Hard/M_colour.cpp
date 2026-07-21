/*M - Coloring Problem
Problem Statement: Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with the same color.

Example 1:
Input:
  
N = 4  
M = 3  
E = 5  
Edges[] = {  
  (0, 1),  
  (1, 2),  
  (2, 3),  
  (3, 0),  
  (0, 2)  
}  
Output:
 1  
Explanation:
It is possible to color the given graph using 3 colors, so the answer is 1 (possible).

Example 2:
Input:
  
N = 3  
M = 2  
E = 3  
Edges[] = {  
  (0, 1),  
  (1, 2),  
  (0, 2)  
}  
Output:
 0  
Explanation: 
It is not possible to color the graph using 2 colors as it forms a triangle, which requires at least 3 colors. Hence, the answer is 0 (not possible).

Solution: We can check each node and try each color from 1 to m, and each time we color a node, we check if it is valid to color it with that color. If it is valid, we move to the next node and repeat the process. If we reach a point where no color can be assigned to a node, we return false and backtrack to the previous node to try a different color. If we successfully color all nodes, we return true and end the process. This is a classic backtracking problem.

time: O(m^n) where n is the number of vertices and m is the number of colors.
space: O(n) for the recursion stack.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canColorUtil(int node, vector<int>& color, vector<vector<int>>& graph, int m) {
        if (node == graph.size()) {
            return true;
        }

        for (int c = 1; c <= m; c++) {
            if (isSafe(node, graph, color, c)) {
                color[node] = c;
                if (canColorUtil(node + 1, color, graph, m)) {
                    return true;
                }
                color[node] = 0; // backtrack
            }
        }
        return false;
    }

    bool isSafe(int node, vector<vector<int>>& graph, vector<int>& color, int c) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[node][i] && color[i] == c) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int N = 4, M = 3, E = 5;
    vector<vector<int>> graph(N, vector<int>(N, 0));
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}};
    for (auto edge : edges) {
        graph[edge.first][edge.second] = 1;
        graph[edge.second][edge.first] = 1; // undirected graph
    }

    Solution sol;
    vector<int> color(N, 0);
    if (sol.canColorUtil(0, color, graph, M)) {
        cout << 1 << endl; // possible
    } else {
        cout << 0 << endl; // not possible
    }

    return 0;
}