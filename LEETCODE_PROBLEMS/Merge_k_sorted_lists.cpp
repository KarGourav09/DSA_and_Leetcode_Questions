/*23. Merge k Sorted Lists, Hard
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

Solution: we will use a priority queue to store the nodes of the linked lists. We will push the head of each linked list into the priority queue. Then we will pop the smallest node from the priority queue and add it to the new linked list. We will then push the next node of the popped node into the priority queue. We will continue this process until the priority queue is empty.

time: O(n log k) where n is the total number of nodes in all the linked lists and k is the number of linked lists.
space: O(k) since we are using a priority queue to store the nodes of the linked lists, which can have at most k nodes at any time.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // A Priority queue (min-heap) to store the nodes of the linked lists which will check the minimum value of the node 
        // and will pop it from the queue and will add it to the new list.
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(
            [](ListNode* a, ListNode* b) { return a->val > b->val; }
        );

        // Push the head of each linked list into the priority queue
        for (ListNode *list : lists)
        {
            if (list)
                pq.push(list);
        }

        // Create a dummy node to build the merged list
        ListNode dummy(0);
        ListNode *current = &dummy;

        // Process the priority queue
        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();

            current->next = node;
            current = node;

            // Push the next node of the popped node into the priority queue
            if (node->next)
                pq.push(node->next);
        }

        return dummy.next;
    }
};

int main()
{
    // Example usage
    ListNode *list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *list3 = new ListNode(2, new ListNode(6));

    vector<ListNode *> lists = {list1, list2, list3};

    Solution sol;
    ListNode *mergedList = sol.mergeKLists(lists); // Output: [1,1,2,3,4,4,5,6]

    // Print the merged list
    while (mergedList)
    {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}