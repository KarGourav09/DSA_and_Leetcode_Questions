/* Find Pairs from Sum in a Doubly Linked List 

Problem: Given a sorted doubly linked list and a target sum, find all pairs of nodes whose values sum up to the target. 

Example:
Input: 1 <-> 2 <-> 3 <-> 4 <-> 5, target = 6
Output: (1,5) and (2,4)

Solution: take two pointers left and right, place the right pointer at the end of the list and left pointer at the start of the list, if the sum of the two nodes is equal to the target, store the pair and move both pointers, if the sum is less than the target, move the left pointer to right, else move the right pointer to left.

time: O(n) where n is the number of nodes in the linked list, as we need to traverse the entire list to find pairs that sum up to the target value.
space: O(1) as we are not using any additional data structures that grow with the
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
    vector<pair<int, int>> findPairWithSum(Node* head, int target){
        Node* left = head;
        Node* right = head;

        vector<pair<int, int>> result;

        while(right->next != nullptr){
            right = right->next;
        }

        while( left->data < right->data){
            int sum = left->data + right->data;
            if(sum == target){
                result.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            } else if(sum < target){
                left = left->next;
            } else {
                right = right->prev;
            }
        }
        return result;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    Solution sol;
    vector<pair<int, int>> result = sol.findPairWithSum(head, 6);

    for(const auto& pair : result){
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }

    return 0;
}