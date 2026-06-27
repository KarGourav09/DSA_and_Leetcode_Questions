/*Search an element in a Linked List
Problem Statement: Given the head of a linked list and an integer value, find out whether the integer is present in the linked list or not. Return true if it is present, or else return false.

Examples
Input: 0->1->2, val = 2
Output: True
Explanation: Since element 2 is present in the list, return true.

Input: 12->5->8->7, val = 6 
Output: False
Explanation: The list does not contain element 6. Therefore, return false.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;     // Data value
    Node* next;   // Pointer to next node

    // Constructor with data and next
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

int main() {
    // Create an array
    vector<int> arr = {12, 5, 8, 7};

    // Create first node
    Node* head = new Node(arr[0]);
    Node* current = head;

    // Create the linked list from the array
    for (int i = 1; i < arr.size(); i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    // Search for an element in the linked list
    int val = 6; // Element to search for
    bool found = false;
    current = head;
    while (current != nullptr) {
        if (current->data == val) {
            found = true;
            break;
        }
        current = current->next;
    }

    // Output the result
    if (found) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }

    return 0;
}