/*Flattening a Linked List
Problem Statement: Given a linked list containing ‘N’ head nodes where every node in the linked list contains two pointers:

‘Next’ points to the next node in the list
‘Child’ pointer to a linked list where the current node is the head

Each of these child linked lists is in sorted order and connected by a 'child' pointer. Your task is to flatten this linked list such that all nodes appear in a single layer or level in a 'sorted order'.

Example 1:

Input: 3 -> 2 -> 1 -> 4 -> 5
            |    |    |    |
            10   7    9    6
                 |         |
                 11        8
                 |
                 12
Output: 1 2 3 4 5 6 7 8 9 10 11 12
Explanation: The linked list is flattened in sorted order, resulting in a single layer with all nodes appearing in ascending order.

Solution: 1. We can use a recursive approach to flatten the linked list. 
We will traverse the main linked list and for each node, then we will recursively flatten its child linked list.
2. We will then merge the flattened child linked list with the main linked list, ensuring that the nodes are in sorted order.

time: O(N) where N is the total number of nodes in the linked list, including all child nodes.
space: O(1) as we are modifying the linked list in place without using any additional data structures.
*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr) {}
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

class Solution {
public:
    Node* FlattenList(Node* head){
        if(!head) return nullptr;

        Node* curr = head;
        while(curr){
            if(curr->child){
                Node* childHead = FlattenList(curr->child);
                Node* nextNode = curr->next;

                curr->next = childHead;
                curr->child = nullptr;

                Node* temp = childHead;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = nextNode;
            }
            curr = curr->next;
        }
        return head;
    }
};

int main() {
    /* Example usage: 3 -> 2 -> 1 -> 4 -> 5
                           |    |    |    |
                           10   7    9    6
                                |         |
                                11        8
                                |
                                12
    */
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head -> next->child = new Node(10);
    head -> next->next->child = new Node(7);
    head -> next->next->child->child = new Node(11);
    head -> next->next->child->child->child = new Node(12);
    head -> next->next->next->child = new Node(9);
    head -> next->next->next->next->child = new Node(6);
    head -> next->next->next->next->child->child = new Node(8);

    Solution sol;
    Node* flattenedHead = sol.FlattenList(head);

    // Print the flattened list i.e, 3 2 10 1 7 11 12 4 9 5 6 8
    Node* curr = flattenedHead;
    while(curr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}

/*
Brute Force Approach: We can use a priority queue (min-heap) to store all the nodes of the linked list. 
We will traverse the main linked list and for each node, we will push its child nodes into the priority queue. 
After traversing the entire list, we will pop nodes from the priority queue and create a new flattened linked list in sorted order.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr) {}
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

class Solution {
public:
    Node* FlattenList(Node* head){
        if(!head) return nullptr;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        Node* curr = head;

        while(curr){
            minHeap.push(curr->data);
            Node* childCurr = curr->child;
            while(childCurr){
                minHeap.push(childCurr->data);
                childCurr = childCurr->child;
            }
            curr = curr->next;
        }

        Node* newHead = new Node(minHeap.top());
        minHeap.pop();
        Node* newCurr = newHead;

        while(!minHeap.empty()){
            newCurr->next = new Node(minHeap.top());
            minHeap.pop();
            newCurr = newCurr->next;
        }

        return newHead;
    }
};
*/