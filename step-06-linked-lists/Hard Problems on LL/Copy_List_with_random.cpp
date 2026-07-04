/*138. Copy List with Random Pointer, Medium
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.

Solution: 1. Create a mapping of original nodes to their corresponding new nodes using a hash map.
2. Iterate through the original linked list and for each node, create a new node with the same value and store it in the hash map.
3. Iterate through the original linked list again and for each node, set the next and random pointers of the corresponding new node using the hash map.

time: O(n), where n is the number of nodes in the linked list. We iterate through the linked list twice, once to create the new nodes and once to set the next and random pointers.
space: O(n), where n is the number of nodes in the linked list. We use a hash map to store the mapping of original nodes to their corresponding new nodes, which requires O(n) space.
*/

#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        
        unordered_map<Node*, Node*> nodeMap;
        Node* current = head;
        
        // First pass: create new nodes and map original to new nodes
        while (current) {
            nodeMap[current] = new Node(current->val);
            current = current->next;
        }
        
        // Second pass: set next and random pointers for new nodes
        current = head;
        while (current) {
            nodeMap[current]->next = nodeMap[current->next];
            nodeMap[current]->random = nodeMap[current->random];
            current = current->next;
        }
        
        return nodeMap[head];
    }
};

int main() {
    // Example usage: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;
    head->next->next->next->next->random = head;

    Solution solution;
    Node* copiedListHead = solution.copyRandomList(head);

    // Print the copied list to verify
    Node* current = copiedListHead;
    while (current) {
        cout << "[" << current->val << ", ";
        if (current->random) {
            cout << current->random->val;
        } else {
            cout << "null";
        }
        cout << "] ";
        current = current->next;
    }
    
    return 0;
}