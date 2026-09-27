/*Implement Stack using Array
Problem Statement: Implement a Last-In-First-Out (LIFO) stack using an array. The implemented stack should support the following operations: push, pop, peek, and isEmpty.

Implement the ArrayStack class:

void push(int x): Pushes element x onto the stack. int pop(): Removes and returns the top element of the stack. int top(): Returns the top element of the stack without removing it. boolean isEmpty(): Returns true if the stack is empty, false otherwise.

Examples
Example 1:
Input:
  
["ArrayStack", "push", "push", "top", "pop", "isEmpty"]  
[[], [5], [10], [], [], []]  
Output:
  [null, null, null, 10, 10, false]  
Explanation:
  ArrayStack stack = new ArrayStack();  
- stack.push(5);  
- stack.push(10);  
- stack.top(); // returns 10  
- stack.pop(); // returns 10  
- stack.isEmpty(); // returns false  

Example 2:
Input:
  
["ArrayStack", "isEmpty", "push", "pop", "isEmpty"]  
[[], [], [1], [], []]  
Output:
 [null, true, null, 1, true]  
Explanation:
  ArrayStack stack = new ArrayStack();  
- stack.push(1);  
- stack.pop(); // returns 1  
- stack.isEmpty(); // returns true

*/

#include<bits/stdc++.h>
using namespace std;

class ArrayStack {
    int *arr;
    int topIndex;
    int capacity;

    public:
    ArrayStack(int size = 100) {
        arr = new int[size];
        capacity = size;
        topIndex = -1;
    }

    void push(int x){
        if(topIndex == capacity - 1){
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++topIndex] = x;
    }

    int pop(){
        if(topIndex == -1){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[topIndex--];
    }

    int top(){
        if(topIndex == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty(){
        return topIndex == -1;
    }
};

int main() {
    ArrayStack stack;

    stack.push(5);
    stack.push(10);
    cout << "Top element: " << stack.top() << endl; // returns 10
    cout << "Popped element: " << stack.pop() << endl; // returns 10
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // returns false

    stack.pop(); // removes 5
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // returns true

    return 0;
}