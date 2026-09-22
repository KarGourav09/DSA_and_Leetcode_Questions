/*Remove duplicates from sorted DLL
Problem Statement: Given the head of a doubly linked list with its values sorted in non-decreasing order. Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.

Return the head of the modified linked list.

Examples
Input: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5

Output: head -> 1 <-> 3 <-> 4 <-> 5
Explanation: Duplicate occurences of 1 and 3 are deleted
Input: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2

Output: head -> 1 <-> 2
Explanation: All duplicate occurences of 1 is deleted

Solution Approach: 1. take two pointers, one for current node and another for next node.
                   2. check if current node's value is equal to next node's value, if yes, then delete the next node and move the next pointer to next node.
                   3. if current node's value is not equal to next node's value, then move both pointers to next node.
                   4. repeat the above steps until next node is not null.
                   5. return the head of the modified linked list.

time: O(n) where n is the number of nodes in the linked list.
space: O(1) as we are not using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class Solution {
public:
    Node* removeDuplicates(Node* head){
        if(head == nullptr) return head;

        Node* curr = head;
        Node* nextNode = head->next;

        while(nextNode != nullptr){
            if(curr->data == nextNode->data){
                curr->next = nextNode->next;
                if(nextNode->next != nullptr){
                    nextNode->next->prev = curr;
                }
                delete nextNode;
                nextNode = curr->next;
            } else {
                curr = nextNode;
                nextNode = nextNode->next;
            }
        }
        return head;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    Solution sol;
    Node* modifiedHead = sol.removeDuplicates(head);

    Node* temp = modifiedHead;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}