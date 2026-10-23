/*102. Binary Tree Level Order Traversal
Medium
Topics
premium lock icon
Companies
Hint
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

Solution:The idea is to traverse the tree recursively, starting from the root at level 0. 
When a node is visited, its value is added to the result array at the index corresponding to its level, and then its left and right children are recursively processed in the same way. 
This effectively performs a level-order traversal using recursion.

time complexity: O(n), where n is the number of nodes in the tree, since each node is visited once.
space complexity: O(n), where n is the number of nodes in the tree, since the result array stores the values of all nodes in the tree.
*/

#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            result.push_back(level);
        }
        return result;
    }
};