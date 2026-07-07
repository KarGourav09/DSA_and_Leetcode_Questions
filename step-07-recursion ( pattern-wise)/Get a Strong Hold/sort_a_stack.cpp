/*Sort a Stack
Problem Statement: You are given a stack of integers. Your task is to sort the stack in descending order using recursion, such that the top of the stack contains the greatest element. You are not allowed to use any loop-based sorting methods (e.g., quicksort, mergesort). You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty).

Examples
Example 1:
Input:
 stack = [4, 1, 3, 2]
Output:
 [4, 3, 2, 1]
Explanation:
 After sorting, the largest element (4) is at the top, and the smallest (1) is at the bottom.

Example 2:
Input:
 stack = [1]
Output:
 [1]
Explanation:
 A single-element stack is already sorted.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void InsertInOrder(stack<int>& s, int element){
        if(s.empty() || s.top() < element){
            s.push(element);
            return;
        }

        int temp = s.top();
        s.pop();
        InsertInOrder(s, element);
        s.push(temp);
    }

public:
    void SortRecursive(stack<int>& s){
        if(s.empty()){
            return;
        }

        int temp = s.top();
        s.pop();
        SortRecursive(s);
        InsertInOrder(s, temp);
    }
};

int main() {
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);

    Solution solution;
    solution.SortRecursive(s);

    cout << "Sorted Stack (Top to Bottom): ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}