/*21. Merge Two Sorted Lists, Easy
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]


Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

Solution: we will iterate each list and compare the values of the nodes, we will add the smaller value to the new list and move the pointer of that list to the next node. We will continue this process until we reach the end of one of the lists. After that, we will add the remaining nodes of the other list to the new list.

time: O(n + m) where n and m are the lengths of the two lists
space: O(1) since we are not using any extra space for the new list, we are just rearranging the pointers of the existing nodes.
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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode *current1 = list1;
        ListNode *current2 = list2;

        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;

        while (current1 != nullptr && current2 != nullptr)
        {
            if (current1->val < current2->val)
            {
                current->next = new ListNode(current1->val);
                current = current->next;
                current1 = current1->next;
            }
            else
            {
                current->next = new ListNode(current2->val);
                current = current->next;
                current2 = current2->next;
            }
        }

        while (current1 != nullptr)
        {
            current->next = new ListNode(current1->val);
            current = current->next;
            current1 = current1->next;
        }

        while (current2 != nullptr)
        {
            current->next = new ListNode(current2->val);
            current = current->next;
            current2 = current2->next;
        }

        return dummy->next;
    }
};

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution sol;
    ListNode *mergedList = sol.mergeTwoLists(list1, list2); // Output: [1,1,2,3,4,4]

    while (mergedList != nullptr)
    {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}