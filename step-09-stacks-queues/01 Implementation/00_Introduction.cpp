/*
 * STACKS AND QUEUES - C++ IMPLEMENTATIONS
 *
 * A stack is LIFO: the last inserted value is removed first.
 * A queue is FIFO: the first inserted value is removed first.
 *
 * This file demonstrates:
 * 1. Stack using a vector
 * 2. Stack using a linked list
 * 3. Queue using a circular vector
 * 4. Queue using a linked list
 * 5. Stack using one queue
 * 6. Queue using two stacks
 * 7. Min stack using a linked list
 *
 * Compile:
 *     g++ -std=c++17 -Wall -Wextra 00_Introduction.cpp -o introduction
 */

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct Result {
    bool hasValue;
    int value;
};

Result emptyResult() {
    return {false, 0};
}

Result valueResult(int value) {
    return {true, value};
}

class ArrayStack {
private:
    vector<int> values;

public:
    explicit ArrayStack(size_t capacity = 16) {
        values.reserve(capacity);
    }

    void push(int value) {
        values.push_back(value);
    }

    Result pop() {
        if (values.empty()) return emptyResult();
        int value = values.back();
        values.pop_back();
        return valueResult(value);
    }

    Result top() const {
        if (values.empty()) return emptyResult();
        return valueResult(values.back());
    }

    bool empty() const {
        return values.empty();
    }
};

class LinkedListStack {
private:
    struct Node {
        int value;
        Node *next;
    };

    Node *topNode = nullptr;

public:
    ~LinkedListStack() {
        while (topNode != nullptr) {
            Node *removed = topNode;
            topNode = topNode->next;
            delete removed;
        }
    }

    void push(int value) {
        topNode = new Node{value, topNode};
    }

    Result pop() {
        if (topNode == nullptr) return emptyResult();
        Node *removed = topNode;
        int value = removed->value;
        topNode = removed->next;
        delete removed;
        return valueResult(value);
    }

    Result top() const {
        if (topNode == nullptr) return emptyResult();
        return valueResult(topNode->value);
    }
};

class CircularQueue {
private:
    vector<int> values;
    size_t frontIndex = 0;
    size_t rearIndex = 0;
    size_t count = 0;

public:
    explicit CircularQueue(size_t capacity = 16) : values(capacity) {}

    bool push(int value) {
        if (full()) return false;
        values[rearIndex] = value;
        rearIndex = (rearIndex + 1) % values.size();
        ++count;
        return true;
    }

    Result pop() {
        if (empty()) return emptyResult();
        int value = values[frontIndex];
        frontIndex = (frontIndex + 1) % values.size();
        --count;
        return valueResult(value);
    }

    bool empty() const {
        return count == 0;
    }

    bool full() const {
        return count == values.size();
    }
};

class LinkedListQueue {
private:
    struct Node {
        int value;
        Node *next;
    };

    Node *frontNode = nullptr;
    Node *rearNode = nullptr;

public:
    ~LinkedListQueue() {
        while (frontNode != nullptr) {
            Node *removed = frontNode;
            frontNode = frontNode->next;
            delete removed;
        }
    }

    void push(int value) {
        Node *node = new Node{value, nullptr};
        if (rearNode == nullptr) frontNode = node;
        else rearNode->next = node;
        rearNode = node;
    }

    Result pop() {
        if (frontNode == nullptr) return emptyResult();
        Node *removed = frontNode;
        int value = removed->value;
        frontNode = removed->next;
        if (frontNode == nullptr) rearNode = nullptr;
        delete removed;
        return valueResult(value);
    }
};

class StackUsingQueue {
private:
    queue<int> values;

public:
    void push(int value) {
        values.push(value);
        size_t previousSize = values.size() - 1;
        while (previousSize-- > 0) {
            values.push(values.front());
            values.pop();
        }
    }

    Result pop() {
        if (values.empty()) return emptyResult();
        int value = values.front();
        values.pop();
        return valueResult(value);
    }
};

class QueueUsingStacks {
private:
    stack<int> input;
    stack<int> output;

    void transferIfNeeded() {
        if (!output.empty()) return;
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }

public:
    void push(int value) {
        input.push(value);
    }

    Result pop() {
        transferIfNeeded();
        if (output.empty()) return emptyResult();
        int value = output.top();
        output.pop();
        return valueResult(value);
    }
};

class MinStack {
private:
    struct Node {
        int value;
        int minimum;
        Node *next;
    };

    Node *topNode = nullptr;

public:
    ~MinStack() {
        while (topNode != nullptr) {
            Node *removed = topNode;
            topNode = topNode->next;
            delete removed;
        }
    }

    void push(int value) {
        int minimum = topNode == nullptr ? value : min(value, topNode->minimum);
        topNode = new Node{value, minimum, topNode};
    }

    Result pop() {
        if (topNode == nullptr) return emptyResult();
        Node *removed = topNode;
        int value = removed->value;
        topNode = removed->next;
        delete removed;
        return valueResult(value);
    }

    Result top() const {
        if (topNode == nullptr) return emptyResult();
        return valueResult(topNode->value);
    }

    Result getMin() const {
        if (topNode == nullptr) return emptyResult();
        return valueResult(topNode->minimum);
    }
};

int main() {
    ArrayStack arrayStack;
    arrayStack.push(10);
    arrayStack.push(20);
    cout << "Array stack pop: " << arrayStack.pop().value << '\n';

    LinkedListStack linkedListStack;
    linkedListStack.push(30);
    linkedListStack.push(40);
    cout << "Linked-list stack pop: " << linkedListStack.pop().value << '\n';

    CircularQueue circularQueue;
    circularQueue.push(50);
    circularQueue.push(60);
    cout << "Circular queue pop: " << circularQueue.pop().value << '\n';

    LinkedListQueue linkedListQueue;
    linkedListQueue.push(70);
    linkedListQueue.push(80);
    cout << "Linked-list queue pop: " << linkedListQueue.pop().value << '\n';

    StackUsingQueue stackUsingQueue;
    stackUsingQueue.push(90);
    stackUsingQueue.push(100);
    cout << "Stack using queue pop: " << stackUsingQueue.pop().value << '\n';

    QueueUsingStacks queueUsingStacks;
    queueUsingStacks.push(110);
    queueUsingStacks.push(120);
    cout << "Queue using stacks pop: " << queueUsingStacks.pop().value << '\n';

    MinStack minStack;
    minStack.push(5);
    minStack.push(2);
    minStack.push(7);
    cout << "Minimum in min stack: " << minStack.getMin().value << '\n';
}
