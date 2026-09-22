#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool sorted = true;
    int previous = 0, value;
    for (int i = 0; i < n; ++i)
    {
        cin >> value;
        if (i && value < previous)
            sorted = false;
        previous = value;
    }
    cout << sorted;
}
// Non-decreasing check. Time: O(n), space: O(1).
