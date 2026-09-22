/*Length of Loop in Linked List


13

Problem Statement: Given the head of a linked list, determine the length of a loop present in the linked list. If there's no loop present, return 0.

Examples
Input: 1->2->3->4->5->3 (loop starts at node with value 3)
Output: 3

Explanation: A cycle exists in the linked list starting at node 3 -> 4 -> 5 and then back to 3. There are 3 nodes present in this cycle.

Solution: we can again use Floyd's Tortoise and Hare algorithm to detect the cycle. 
If a cycle is detected, we can then make one pointer traverse the cycle until it meets the other pointer again, counting the number of nodes traversed to determine the length of the loop.
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
    int countLoopLength(ListNode* head){
        if (head == nullptr || head->next == nullptr) {
            return 0;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Cycle detected, now count the length of the loop
                int loopLength = 1;
                ListNode* current = slow->next;
                while (current != slow) {
                    loopLength++;
                    current = current->next;
                }
                return loopLength;
            }
        }

        return 0; // No cycle detected
    }
};

int main(){
    Solution solution;

    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // Creating a loop

    cout << "Loop created." << endl;
    int loopLength = solution.countLoopLength(head);
    cout << "Length of the loop: " << loopLength << endl;
}