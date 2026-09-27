#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedListQueue {
private:
    Node* front;
    Node* rear;

public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Adds element x to the end of the queue
    void push(int x) {
        Node* newNode = new Node(x);
        
        // If queue is empty, new node is both front and rear
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        // Add the new node at the end of queue and update rear
        rear->next = newNode;
        rear = newNode;
    }

    // Removes and returns the front element of the queue
    int pop() {
        if (isEmpty()) {
            return -1; // Queue underflow
        }

        Node* temp = front;
        int poppedValue = temp->data;

        front = front->next;

        // If front becomes NULL, reset rear to NULL as well
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return poppedValue;
    }

    // Returns the front element without removing it
    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return front->data;
    }

    // Returns true if the queue is empty, false otherwise
    bool isEmpty() {
        return front == nullptr;
    }

    // Destructor to clear allocated memory
    ~LinkedListQueue() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    LinkedListQueue queue;

    queue.push(3);
    queue.push(7);
    cout << "Peek: " << queue.peek() << endl;       // Output: 3
    cout << "Pop: " << queue.pop() << endl;         // Output: 3
    cout << "IsEmpty: " << boolalpha << queue.isEmpty() << endl; // Output: false

    return 0;
}