/*876. Middle of the Linked List, Easy
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 
Constraints:
The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100

Optimal Approach: [TortoiseHare Method]
We can use the two-pointer technique to find the middle node of a singly linked list. 
We will maintain two pointers, slow and fast. The slow pointer will move one step at a time, while the fast pointer will move two steps at a time. 
When the fast pointer reaches the end of the list, the slow pointer will be at the middle node. 
If there are two middle nodes, the slow pointer will point to the second middle node.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; fast != nullptr && fast->next != nullptr; i++) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    ListNode* middle = solution.middleNode(head);

    // Printing the middle node and its subsequent nodes
    cout << "Middle node and subsequent nodes: "; // Output: 3 4 5
    while (middle != nullptr) {
        cout << middle->val << " ";
        middle = middle->next;
    }
    cout << endl;

    // Freeing allocated memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

/*
Brute Force Approach: We can traverse the linked list to count the number of nodes, and then traverse it again to reach the middle node.
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        int middle = count / 2;
        current = head;
        for (int i = 0; i < middle; i++) {
            current = current->next;
        }
        return current;
    }
};
*/