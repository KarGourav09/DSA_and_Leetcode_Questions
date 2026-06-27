/*Insert at the head of a Linked List
Problem Statement: Given a linked list and an integer value val, insert a new node with that value at the beginning (before the head) of the list and return the updated linked list.

Examples
Input: 0->1->2, val = 5 
Output: 5->0->1->2
Explanation: We need to insert the value 5 before the head of the given Linked List.

Input: 12->5->8->7, val = 4
Output: 4->12->5->8->7
Explanation: We need to insert the value 4 before the head of the given Linked List.

Solution: 1. Create a new node with data as the given value and pointing to the head. This node will be our new head of the linked list.
          2. Now, return the new node as the head of the updated Linked List.

         Time: O(1), creating a new node and updating the head takes constant time.
         Space: O(1) , only one extra node is created to insert at the head of the linked list.
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

int main() {
    // Create an array
    vector<int> arr = {0, 1, 2};

    // Create first node
    Node* head = new Node(arr[0]);

    // Create the rest of the linked list
    Node* current = head;
    for (int i = 1; i < arr.size(); i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    // Insert at head
    int val = 5;
    Node* newHead = new Node(val, head);

    // Print the updated linked list
    current = newHead;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}