/*Add 1 to a number represented by LL
Problem Statement: Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.

The number will contain no leading zeroes except when the value represented is zero itself.

Examples
Input: 4->5->6

Output: 4->5->7
Explanation: 456 + 1 = 457
Input: 9->9->9

Output: 1->0->0->0
Explanation: 999 + 1 = 1000

Solution: 1. Reverse the linked list so the least significant digit (ones place) is at the head.
2. Add 1 to the head node's value.
3. If the sum is less than 10, we are done. If the sum is 10 or more, set the current node's value to 0 and carry over 1 to the next node.
4. Repeat step 3 for each node until there are no more nodes or there is no carry.
5. Reverse the linked list again to restore the original order of digits.

time complexity: O(n) where n is the number of nodes in the linked list.
space complexity: O(1) since we are modifying the linked list in place and not using any additional data structures.
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

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }


    ListNode* plusOne(ListNode* head) {
        ListNode* reversedHead = reverseList(head);

        ListNode* prev = nullptr;
        ListNode* curr = reversedHead;
        int carry = 1;

        while (curr) {
            int sum = curr->val + carry;
            if (sum < 10) {
                curr->val = sum;
                carry = 0; 
                break;
            } else {
                curr->val = 0; 
                carry = 1;
            }
            prev = curr;
            curr = curr->next;
        }

        if (carry == 1 && prev != nullptr) {
            prev->next = new ListNode(1);
        }
        return reverseList(reversedHead);
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(9);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);

    ListNode* result = solution.plusOne(head);

    // Output: 1->0->0->0
    while (result) {
        cout << result->val;
        if (result->next) cout << "->";
        result = result->next;
    }
    cout << endl;

    return 0;
}