/*2. Add Two Numbers, Medium
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

solution: 1. Reverse both linked lists so that the least significant digit (ones place) is at the head.
2. Initialize a carry variable to 0.
3. Traverse both linked lists simultaneously, adding the corresponding digits along with the carry.
4. If the sum is less than 10, set the current node's value to the sum and set carry to 0. If the sum is 10 or more, set the current node's value to sum % 10 and set carry to sum / 10.
5. If one linked list is longer than the other, continue adding the remaining digits along with the carry.
6. If there is still a carry after processing both linked lists, create a new node with the carry value and append it to the result linked list.

time complexity: O(max(m, n)) where m and n are the number of nodes in the two linked lists.
space complexity: O(1) since we are modifying the linked lists in place and not using
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next; // Move to next digit
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next; // Move to next digit
            }
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            
            curr = curr->next;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

int main() {
    Solution solution;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = solution.addTwoNumbers(l1, l2);

    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}