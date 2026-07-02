/*Sort a Linked List of 0's 1's and 2's by changing links
Problem Statement: Given a linked list containing only 0's, 1's, and 2's, sort the linked list by rearranging the links (not by changing the data values).

Examples
Input: 1 -> 2 -> 0 -> 1 -> 0 -> 2 -> NULL
Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL
Input: 2 -> 1 -> 2 -> 0 -> 0 -> 1 -> NULL
Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL

Solution: 1. We can create three dummy nodes for 0's, 1's, and 2's. We will traverse the linked list and attach the nodes to the corresponding dummy node based on their value.
2. Finally, we will connect the three lists and return the head of the sorted linked list

time: O(n) and space: O(1)
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
    ListNode* sortList(ListNode* head){
        ListNode *zeroHead = new ListNode(0), *zeroTail = zeroHead;
        ListNode *oneHead = new ListNode(0), *oneTail = oneHead;
        ListNode *twoHead = new ListNode(0), *twoTail = twoHead;

        ListNode *curr = head;
        while (curr) {
            if (curr->val == 0) {
                zeroTail->next = curr;
                zeroTail = zeroTail->next;
            } else if (curr->val == 1) {
                oneTail->next = curr;
                oneTail = oneTail->next;
            } else {
                twoTail->next = curr;
                twoTail = twoTail->next;
            }
            curr = curr->next;
        }

        // Connect the three lists
        zeroTail->next = oneHead->next;
        oneTail->next = twoHead->next;
        twoTail->next = nullptr;

        // Return the head of the sorted list
        return zeroHead->next;
    }

};

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(0);
    head->next->next->next->next->next = new ListNode(2);

    Solution solution;
    ListNode* sortedHead = solution.sortList(head);

    // Print the sorted linked list 0-> 0 -> 1 -> 1 -> 2 -> 2 -> NULL
    while (sortedHead) {
        cout << sortedHead->val << " -> ";
        sortedHead = sortedHead->next;
    }
    cout << "NULL" << endl;

    return 0;
}