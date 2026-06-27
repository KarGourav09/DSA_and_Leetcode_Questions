/*Find the Length of a Linked List
Problem Statement: Given the head of a linked list, print the length of the linked list.

Examples
Input: 0->1->2 
Output: 3
Explanation: The list has a total of 3 nodes, thus the length of the list is 3.

Input: 12->5->8->7
Output: 4
Explanation: The list has a total of 4 nodes, thus the length of the list is 4.

Solution: 1. Initialize a temporary pointer to the head of the list. The temporary pointer will be used to traverse the list.
          2. Traverse the linked list until the the current node is not null.
          3. At every node, increment the counter to count number of nodes.
          4. After reaching the end of the linked list, return the count. This will be your total number of nodes which is the length of the linked list.

          time: O(n) where n is the number of nodes in the linked list.
          Space: O(1) as we are using a constant amount of space to store the count and the temporary pointer.
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

    // Calculate the length of the linked list
    int length = 0;
    current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }

    // Print the length of the linked list
    cout << "Length of the linked list: " << length << endl;

    return 0;
}