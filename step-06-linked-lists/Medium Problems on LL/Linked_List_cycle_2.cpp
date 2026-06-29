/*142. Linked List Cycle II, Medium
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?

Solution: Use Floyd's Tortoise and Hare algorithm to detect the cycle. 
If a cycle is detected, find the entry point of the cycle by resetting one pointer to the head and moving both pointers one step at a time until they meet again. 
The meeting point will be the start of the cycle.

time: O(n) - where n is the number of nodes in the linked list. In the worst case, we may need to traverse the entire list to detect a cycle and find its entry point.
space: O(1) - we are using a constant amount of space for the two pointers, regardless of the size of the input linked list.
*/

#include <bits/stdc++.h>
using namespace std;



  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return slow; // Cycle detected, return the meeting point
            }
        }

        return nullptr; // No cycle found
    }
};

int main() {
    // Example usage
    ListNode* head = new ListNode(0);
    for(int i = 1; i < 10; ++i) {
        ListNode* newNode = new ListNode(i);
        head->next = newNode;
        head = newNode;
    }

    Solution solution;
    ListNode* cycleNode = solution.detectCycle(head);

    if (cycleNode != nullptr) {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}


/*
Brute Approach: Use a hash set to store visited nodes. 
Traverse the linked list and check if a node has already been visited. 
If it has, return that node as the start of the cycle. 
If the end of the list is reached without finding a cycle, return null.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode* current = head;

        while (current != nullptr) {
            if (visited.find(current) != visited.end()) {
                return current; // Cycle detected, return the node
            }
            visited.insert(current);
            current = current->next;
        }

        return nullptr; // No cycle found
    }
};
*/