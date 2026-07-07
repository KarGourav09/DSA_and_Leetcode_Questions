/*Reverse a stack using recursion
Problem Statement: You are given a stack of integers. Your task is to reverse the stack using recursion. You may only use standard stack operations (push, pop, top/peek, isEmpty). You are not allowed to use any loop constructs or additional data structures like arrays or queues.

Your solution must modify the input stack in-place to reverse the order of its elements.

Examples
Example 1:
Input:
 stack = [4, 1, 3, 2]  
Output:
 [2, 3, 1, 4]

Example 2:
Input:
 stack = [10, 20, -5, 7, 15]  
Output:
 [15, 7, -5, 20, 10]


 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void InsertAtBottom(stack<int>& s, int element){
        if(s.empty()){
            s.push(element);
            return;
        }

        int temp = s.top();
        s.pop();
        InsertAtBottom(s, element);
        s.push(temp);
    }
public:
    void ReverseStack(stack<int>& s){
        if(s.empty()){
            return;
        }

        int temp = s.top();
        s.pop();
        ReverseStack(s);
        InsertAtBottom(s, temp);
    }
};

int main() {
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);

    Solution solution;
    solution.ReverseStack(s);

    cout << "Reversed stack: ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}