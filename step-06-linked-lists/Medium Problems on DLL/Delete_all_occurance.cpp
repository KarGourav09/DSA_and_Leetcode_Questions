/*Delete all occurrences of a key in DLL
Problem Statement: Given the head of a doubly linked list and an integer target. Delete all nodes in the linked list with the value target and return the head of the modified linked list.

Examples
Input: head -> 1 <-> 2 <-> 3 <-> 1 <-> 4, target = 1

Output: head -> 2 <-> 3 <-> 4
Input: head -> 2 <-> 3 <-> -1 <-> 4 <-> 2, target = 2

Output: head -> 3 <-> -1 <-> 4

Solution Approach: 1.Iterate through the linked list and check if the current node's value is equal to the target value. 
If it is, delete the node by updating the previous and next pointers of the adjacent nodes. 
If the current node is the head, update the head pointer to the next node. 
Continue this process until the end of the list is reached.

time: O(n) where n is the number of nodes in the linked list, as we need to traverse the entire list to check for occurrences of the target value.
space: O(1) as we are not using any additional data structures that grow with the input size. We are only using a few pointers to keep track of the current node and its neighbors.
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
    Node* deleteAllOccurrences(Node* head, int target){
        Node* curr = head;

        while(curr != nullptr){
            if(curr->data == target){
                Node* temp = curr;
                if(curr->prev != nullptr){
                    curr->prev->next = curr->next;
                } else {
                    head = curr->next; // Update head if the current node is the head
                }
                if(curr->next != nullptr){
                    curr->next->prev = curr->prev;
                }
                curr = curr->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};

int main() {
    // Create a sample doubly linked list: 1 <-> 2 <-> 3 <-> 1 <-> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(1);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;

    int target = 1;

    Solution sol;
    head = sol.deleteAllOccurrences(head, target);

    // Print the modified linked list
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    
    return 0;
}