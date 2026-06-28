/*206. Reverse Linked List, Easy
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []
 
Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 
Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

Brute Force Approach: 1. Create a new linked list and traverse the original linked list, adding each node to the front of the new linked list. 
                        This will reverse the order of the nodes. 
                      2. Return the head of the new linked list.

Optimal Approach: 1. Initialize three pointers: prev as nullptr, curr as head, and next as nullptr.
                  2. Traverse the linked list while curr is not nullptr:
                     a. Store the next node: next = curr->next
                     b. Reverse the link: curr->next = prev
                     c. Move prev and curr one step forward: prev = curr, curr = next
                  3. Return prev as the new head of the reversed linked list.

Recursive Approach: 1. If the head is nullptr or head->next is nullptr, return head (base case).
                    2. Recursively reverse the rest of the list: ListNode* newHead = reverseList(head->next)
                    3. Set head->next->next = head to reverse the link.
                    4. Set head->next = nullptr to avoid cycles.
                    5. Return newHead as the new head of the reversed linked list.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(0);
    for(int i = 1; i <= 5; i++) {
        ListNode* newNode = new ListNode(i);
        ListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head->next);

    // Printing the reversed linked list
    ListNode* current = reversedHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}