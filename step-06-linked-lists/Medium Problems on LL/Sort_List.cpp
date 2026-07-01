/*148. Sort List, Medium
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

Solution: 1. First iterate through the LL and fins the smallest element and make it the head of the LL.
2. Now iterate through the LL and find the next smallest element and make it the next of head.
3. Repeat the above step until the end of the LL is reached.

time: O(n^2) and space: O(1)

optimised solution: 1. Use merge sort to sort the linked list in O(nlogn) time and O(1) space.
                    2. Use the fast and slow pointer technique to find the middle of the linked list and split it into two halves.
                    3. Recursively sort the two halves and merge them together.

time: O(nlogn) and space: O(1)
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
 

/*class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* curr = head;
        while (curr) {
            ListNode* minNode = curr;
            ListNode* temp = curr->next;
            while (temp) {
                if (temp->val < minNode->val) {
                    minNode = temp;
                }
                temp = temp->next;
            }
            swap(curr->val, minNode->val);
            curr = curr->next;
        }
        return head;
    }
};
*/

class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right) {
        // Base cases: if one list is empty, return the other
        if (!left) return right;
        if (!right) return left;

        ListNode* result = nullptr;
        if (left->val < right->val) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        return merge(left, right);
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    head = sol.sortList(head);

    ListNode* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}