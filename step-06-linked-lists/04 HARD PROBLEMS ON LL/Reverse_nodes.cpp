/*25. Reverse Nodes in k-Group, Hard
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?

Solution: 1. We can solve this problem by iterating through the linked list and reversing the nodes in chunks of size k. 
We will use a dummy node to simplify the handling of the head of the list. 
For each chunk, we will check if there are at least k nodes remaining; if so, we will reverse that chunk and link it back to the previous part of the list. 
If there are fewer than k nodes left, we will leave them as they are.

time complexity: O(n), where n is the number of nodes in the linked list, as we traverse the list once.
space complexity: O(1), as we are using a constant amount of extra space for pointers and variables.
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
    ListNode* reverse(ListNode* head) {
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

    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != nullptr && k > 1) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupTail = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* kthNode = getKthNode(curr, k);
            
            if (kthNode == nullptr) {
                prevGroupTail->next = curr;
                break;
            }

            ListNode* nextGroupHead = kthNode->next;
            kthNode->next = nullptr;

            prevGroupTail->next = reverse(curr);

            prevGroupTail = curr; 
            curr = nextGroupHead;
        }

        ListNode* finalHead = dummy->next;
        delete dummy;
        return finalHead;
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 3;
    ListNode* result = solution.reverseKGroup(head, k); // Correct Output: 3 2 1 4 5

    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}