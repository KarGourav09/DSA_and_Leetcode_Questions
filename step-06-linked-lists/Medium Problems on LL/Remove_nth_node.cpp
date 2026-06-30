/*19. Remove Nth Node From End of List, Medium
Given the head of a linked list, remove the nth node from the end of the list and return its head.


Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]


Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz


Follow up: Could you do this in one pass?

Solution: 1. we can just reverse the linked list and then remove the nth node from the start of the list.
Then we can reverse the linked list again to get the final answer.

2. Or we can iterate the linked list then count its length and then remove the (length-n)th node from the start of the list.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, reversedHead);
        ListNode* current = dummy;

            for(int i = 0; i < n - 1 && current != nullptr; ++i) {
                current = current->next;
            }
            if(current != nullptr && current->next != nullptr) {
                ListNode* nodeToRemove = current->next;
                current->next = current->next->next;
                delete nodeToRemove;
            }
        ListNode* newReversedHead = dummy->next;
        delete dummy;
        return reverseList(newReversedHead);
    }
};
*/

int main()
{
    // Creating a linked list: [1,2,3,4,5]
    ListNode *head = new ListNode(0);
    for (int i = 1; i <= 5; i++)
    {
        ListNode *newNode = new ListNode(i);
        ListNode *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    Solution solution;
    int n = 2; // Remove the 2nd node from the end
    ListNode *modifiedHead = solution.removeNthFromEnd(head->next, n);

    // Printing the modified linked list
    ListNode *current = modifiedHead;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}

class Solution
{
public:
    int Length(ListNode *head)
    {
        int length = 0;
        ListNode *current = head;
        while (current != nullptr)
        {
            length++;
            current = current->next;
        }
        return length;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int length = Length(head);
        int position = length - n;

        if (position == 0)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode *current = head;
        for (int i = 0; i < position - 1; ++i)
        {
            current = current->next;
        }

        ListNode *nodeToRemove = current->next;
        current->next = current->next->next;
        
        delete nodeToRemove;

        return head;
    }
};