/*155. Min Stack, Medium
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int value) pushes the element value onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.



Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    struct Node
    {
        int val;
        int minVal;
        Node *next;

        Node(int v, int m, Node *n) : val(v), minVal(m), next(n) {}
    };

    Node *head;

public:
    MinStack() : head(nullptr) {}

    ~MinStack()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(int val)
    {
        if (head == nullptr)
        {
            head = new Node(val, val, nullptr);
        }
        else
        {
            int currentMin = (val < head->minVal) ? val : head->minVal;
            head = new Node(val, currentMin, head);
        }
    }

    void pop()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    int top()
    {
        return head->val;
    }

    int getMin()
    {
        return head->minVal;
    }
};

int main()
{
    MinStack minStack;

    cout << "[null, ";
    minStack.push(-2);
    cout << "null, ";
    minStack.push(0);
    cout << "null, ";
    minStack.push(-3);
    cout << "null, ";

    cout << minStack.getMin() << ", "; // Output: -3
    minStack.pop();
    cout << "null, ";

    cout << minStack.top() << ", ";     // Output: 0
    cout << minStack.getMin() << "]\n"; // Output: -2

    return 0;
}