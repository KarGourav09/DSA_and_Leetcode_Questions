/*Insert at end of Doubly Linked List
Problem Statement: Given a doubly linked list, and a value ‘k’, insert a node having value ‘k’ at the end of the doubly linked list.

Example 1:
Input Format:
  
DLL: 1 <-> 2 <-> 3 <-> 4  
Value to be Inserted: 6  
Result:
  DLL: 1 <-> 2 <-> 3 <-> 4 <-> 6  
Explanation:
  A new node with value 6 has been inserted at the end of the doubly linked list after the tail node.

Example 2:
Input Format:
  
DLL: 10 <-> 20 <-> 30  
Value to be Inserted: 40  
Result:
  DLL: 10 <-> 20 <-> 30 <-> 40  
Explanation:
  In this case, a new node with value 40 is inserted after 30, which is at the end of the doubly linked list.

Solution Approach:
1. Create a new node with the given value ‘k’.
2. Traverse the doubly linked list to reach the last node (tail).
3. Update the next pointer of the last node to point to the new node.
4. Update the previous pointer of the new node to point to the last node.
*/

#include <bits/stdc++.h>
using namespace std;


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

int main(){
    vector<int> arr = {2, 5, 8, 7};

    int k = 6; // Value to be inserted at the end of the doubly linked list

    // Creating the head node of the doubly linked list
    Node* head = new Node(arr[0]);

    // Creating the rest of the doubly linked list from the array
    Node* current = head;
    for(int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    // Inserting the new node with value 'k' at the end of the doubly linked list
    Node* newNode = new Node(k);
    current->next = newNode;
    newNode->prev = current;
    newNode->next = nullptr;

    // Printing the updated doubly linked list
    current = head;
    while(current != nullptr) {
        cout << current->data;
        if(current->next != nullptr) {
            cout << " <-> ";
        }
        current = current->next;
    }
}