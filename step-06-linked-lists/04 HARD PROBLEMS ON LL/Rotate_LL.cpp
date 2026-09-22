/*61. Rotate List, Medium
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

Solution: 1. we can iterate and find the length of LL, then we have to take till l - k element in list1 and then we have to take the rest of the elements in list2 and then we have to join list2 first and then list1.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* tail = head;
        int len = 1;
        while (tail->next != nullptr) {
            len++;
            tail = tail->next;
        }

        k = k % len;
        if (k == 0) return head; 

        tail->next = head;

        ListNode* newTail = head;
        for (int i = 0; i < len - k - 1; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    int k = 2;
    ListNode* rotatedList = sol.rotateRight(head, k); // Output: 4 5 1 2 3 

    while(rotatedList != nullptr){
        cout << rotatedList->val << " ";
        rotatedList = rotatedList->next;
    }
    cout << endl;
    return 0;
}