/*24. Swap Nodes in Pairs, Medium
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]
Explanation:

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Example 4:
Input: head = [1,2,3]
Output: [2,1,3]
 

Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

Solution: We can use Recursion to solve this problem. We can swap the first two nodes and then recursively call the function for the rest of the list. The base case will be when the head is NULL or there is only one node left in the list.

time: O(n) where n is the number of nodes in the linked list. We are traversing the entire list once.
space: O(n) where n is the number of nodes in the linked list. The space complexity is due to the recursion stack.

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
    ListNode* swapPairs(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Swap the first two nodes
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;

        return newHead;
    }
};

int main() {
    Solution solution;

    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode* swappedHead = solution.swapPairs(head);

    // Print the swapped list i.e. 2 -> 1 -> 4 -> 3
    while (swappedHead != nullptr) {
        cout << swappedHead->val << " ";
        swappedHead = swappedHead->next;
    }
    cout << endl;

    return 0;
}