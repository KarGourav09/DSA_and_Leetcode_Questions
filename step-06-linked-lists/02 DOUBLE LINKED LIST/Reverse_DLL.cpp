/*Reverse a Doubly Linked List
Problem Statement: Given a doubly linked list of size ‘N’ consisting of positive integers, your task is to reverse it and return the head of the modified doubly linked list.

Examples
Input : DLL - 1 <-> 2 <-> 3 <-> 4
Output: DLL - 4 <-> 3 <-> 2 <-> 1

Explanation
: The doubly linked list is reversed and its last node is returned at the new head pointer.

Brute Force : A brute-force approach involves replacing data in a doubly linked list. First, we traverse the list and store node data in a stack. 
              Then, in a second pass, we assign elements from the stack to nodes, ensuring a reverse order replacement since stacks follow the Last-In-First-Out (LIFO) principle.
              Initialization a temp pointer to the head of the doubly linked list and a stack data structure to store the values from the list.
              Traverse the doubly linked list with the temp pointer and while traversing push the value at the current node temp onto the stack. Move the temp to the next node continuing until temp reaches null indicating the end of the list.
              Reset the temp pointer back to the head of the list and in this second iteration pop the element from the stack, replace the data at the current node with the popped value from the top of the stack and move temp to the next node. 
              Repeat this step until temp reaches null or the stack becomes empty.


Optimized Approach : The optimized approach involves reversing the links between nodes in a single traversal. 
                     We initialize a temp pointer to the head of the doubly linked list and a prev pointer to null. 
                     While traversing the list, we store the next node in a temporary variable, update the current node's next pointer to point to the previous node, and set the previous node's back pointer to point to the current node. 
                     We then move the prev pointer to the current node and advance the temp pointer to the next node. 
                     This process continues until we reach the end of the list, at which point we return the prev pointer as it now points to the new head of the reversed list.

*/

#include <bits/stdc++.h>
using namespace std;

// Class representing a node in Doubly Linked List
class Node {
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

    // Printing the original doubly linked list
    cout << "Original Doubly Linked List: ";
    current = head;
    while(current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    // Reversing the doubly linked list
    Node* prev = nullptr;
    current = head;

    while(current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }

    head = prev;

    // Printing the reversed doubly linked list
    cout << "\nReversed Doubly Linked List: ";
    current = head;
    while(current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}