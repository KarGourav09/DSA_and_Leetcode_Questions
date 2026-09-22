/*328. Odd Even Linked List, Medium
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.



Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]


Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106

Solution Approach:
1. Create two dummy nodes, one for odd indexed nodes and one for even indexed nodes.
2. Traverse the original linked list and separate the nodes into odd and even indexed lists based on their position.
3. After the traversal, connect the odd indexed list to the even indexed list.

time: O(n) - where n is the number of nodes in the linked list, as we traverse the list once.
space: O(1) - we are using a constant amount of extra space for the dummy
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
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *oddHead = new ListNode(-1), *oddtail = oddHead;
        ListNode *evenHead = new ListNode(-1), *eventail = evenHead;

        ListNode *current = head;

        int index = 1; // Start with index 1 for the first node

        while (current != nullptr)
        {
            ListNode *temp = current;
            current = current->next;
            temp->next = nullptr;

            if (index & 1)
            { // Odd index
                oddtail->next = temp;
                oddtail = oddtail->next;
            }
            else
            {
                eventail->next = temp;
                eventail = eventail->next;
            }
            index++;
        }
        ListNode *reorderedHead = oddHead->next;
        oddtail->next = evenHead->next;

        delete oddHead;  // Free dummy odd head
        delete evenHead; // Free dummy even head

        return reorderedHead;
    }
};

int main()
{
    // Creating a linked list: [2,1,3,5,6,4,7]
    vector<int> values = {2, 1, 3, 5, 6, 4, 7};
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    for (size_t i = 1; i < values.size(); i++)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    Solution solution;
    ListNode *reorderedHead = solution.oddEvenList(head);

    // Printing the reordered linked list
    cout << "Reordered linked list: "; // Output: 2 3 6 7 1 5 4
    while (reorderedHead != nullptr)
    {
        cout << reorderedHead->val << " ";
        reorderedHead = reorderedHead->next;
    }
    cout << endl;

    // Freeing allocated memory
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}