/*Implement Queue Using Array


5

Problem Statement: Implement a First-In-First-Out (FIFO) queue using an array. The implemented queue should support the following operations: push, dequeue, pop, and isEmpty.

Implement the ArrayQueue class:

void push(int x): Adds element x to the end of the queue.
int pop(): Removes and returns the front element of the queue.
int peek(): Returns the front element of the queue without removing it.
boolean isEmpty(): Returns true if the queue is empty, false otherwise.

Examples
Example 1:
Input:
 
["ArrayQueue", "push", "push", "peek", "pop", "isEmpty"]  
[[], [5], [10], [], [], []]  
Output:
 [null, null, null, 5, 5, false]  
Explanation:
  
ArrayQueue queue = new ArrayQueue();  
- queue.push(5);  
- queue.push(10);  
- queue.peek(); // returns 5  
- queue.pop(); // returns 5  
- queue.isEmpty(); // returns false  

Example 2:
Input:
  
["ArrayQueue", "isEmpty"]  
[[]]  
Output:
 [null, true]  

Explanation:
  
ArrayQueue queue = new ArrayQueue();  
- queue.isEmpty(); // returns true
*/

#include<bits/stdc++.h>
using namespace std;

class ArrayQueue {
    int *arr;
    int frontIndex;
    int rearIndex;
    int capacity;

    public:
    ArrayQueue(int size = 100) {
        arr = new int[size];
        capacity = size;
        frontIndex = 0;
        rearIndex = -1;
    }

    void push(int x){
        if(rearIndex == capacity - 1){
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[++rearIndex] = x;
    }

    int pop(){
        if(frontIndex > rearIndex){
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return arr[frontIndex++];
    }

    int peek(){
        if(frontIndex > rearIndex){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    bool isEmpty(){
        return frontIndex > rearIndex;
    }
};

int main() {
    ArrayQueue queue;

    queue.push(5);
    queue.push(10);
    cout << queue.peek() << endl; // returns 5
    cout << queue.pop() << endl;   // returns 5
    cout << (queue.isEmpty() ? "true" : "false") << endl; // returns false

    return 0;
}