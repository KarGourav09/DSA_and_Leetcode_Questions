/*Delete Last Node of a Doubly Linked List
Problem Statement: Given a Doubly Linked List, delete the last node of the Doubly Linked List.

Examples
Input:  DLL: 1 <-> 3 <-> 4 <-> 1

Output: DLL: 1 <-> 3 <-> 4

Explanation: Last node of the Doubly Linked List to be deleted is 1.


Solution: To delete the tail of a doubly linked list, we update the linkage between its last node and its second last node. Since a doubly linked list is bidirectional, 
          we set the second last node's next pointer and the last node's back pointer to null. Then, we can return the head of the doubly linked list as the result.

    Some edge cases to consider is when the list is empty or when there is only one node in the entire list.
        If the list is empty, return immediately as there is nothing to delete.
        If list has only one node, delete the node and return an empty list.
        Traverse the doubly linked list to the last node and keep track of it using the tail pointer.
        Access the second last node using the tail's back pointer
        Set the next pointer of the second last node to null. This step effectively disconnects the initial tail node from the list in the forward direction, making second last node as the new tail node.
        Set the back pointer of the tail node to null. This ensures that the tail node no longer points back to the second last node.
        Return the head of the doubly linked list as the result.
*/

#include <bits/stdc++.h>
using namespace std;

// Class representing a node in Doubly Linked List
class Node {
public:
    void deleteNode(Node* head) {
        if (head == nullptr) {
            return;
        }

        Node* current = head;

        // Traverse to the last node
        while (current->next != nullptr) {
            current = current->next;
        }

        // If the list has only one node
        if (current->prev == nullptr) {
            delete current;
            head = nullptr;
            return;
        }

        // Update the previous node's next pointer to null
        current->prev->next = nullptr;

        // Delete the last node
        delete current;
    }

public:
    // Stores data of the node
    int data;

    // Pointer to the next node
    Node* next;

    // Pointer to the previous node
    Node* prev;

    // Constructor when data, next and prev are provided
    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    // Constructor when only data is provided
    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

int main() {
    // Initializing an array to create nodes
    vector<int> arr = {2, 5, 8, 7};

    // Creating the head node of the doubly linked list
    Node* head = new Node(arr[0]);

    Node* current = head;
    for(int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    // Delete the last node
    head->deleteNode(head);

    current = head;
    for(int i = 0; i < arr.size() - 1; i++) {
        cout << current->data << " ";
        current = current->next;
    }
}