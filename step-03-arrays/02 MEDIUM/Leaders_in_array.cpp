/*Leaders in an Array
Problem Statement: .

Example 1:
Input:
 arr = [4, 7, 1, 0]  
Output:
 7 1 0  
Explanation:
 The rightmost element (0) is always a leader.  
7 and 1 are greater than the elements to their right, making them leaders as well.*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> findLeaders(const vector<int>& arr)
{
    vector<int> leaders;
    int currentLeader = arr[arr.size() - 1]; // Start with the rightmost element as the initial leader
    leaders.push_back(currentLeader);
    for(int i = arr.size() - 2; i >= 0; i--)
    {
        if(arr[i] > currentLeader) // If the current element is greater than the current leader, it becomes the new leader
        {
            currentLeader = arr[i];
            leaders.push_back(currentLeader);
        }
    }
    return leaders;
}

int main()
{
    vector<int> arr = {4, 7, 1, 0};
    vector<int> leaders = findLeaders(arr);
    
    cout << "Leaders in the array: ";
    for(int i = leaders.size() - 1; i >= 0; i--)
    {
        cout << leaders[i] << " ";
    }
    cout << endl;
    
    return 0;
}