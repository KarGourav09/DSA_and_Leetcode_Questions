/*A. Halloumi Boxes
time limit per test1 second
memory limit per test256 megabytes
Theofanis is busy after his last contest, as now, he has to deliver many halloumis all over the world. He stored them inside n
 boxes and each of which has some number ai
 written on it.

He wants to sort them in non-decreasing order based on their number, however, his machine works in a strange way. It can only reverse any subarray†
 of boxes with length at most k
.

Find if it's possible to sort the boxes using any number of reverses.

†
 Reversing a subarray means choosing two indices i
 and j
 (where 1≤i≤j≤n
) and changing the array a1,a2,…,an
 to a1,a2,…,ai−1,aj,aj−1,…,ai,aj+1,…,an−1,an
. The length of the subarray is then j−i+1
.

Input
The first line contains a single integer t
 (1≤t≤100
) — the number of test cases.

Each test case consists of two lines.

The first line of each test case contains two integers n
 and k
 (1≤k≤n≤100
) — the number of boxes and the length of the maximum reverse that Theofanis can make.

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤109
) — the number written on each box.

Output
For each test case, print YES (case-insensitive), if the array can be sorted in non-decreasing order, or NO (case-insensitive) otherwise.

Example
Input
5
3 2
1 2 3

3 1
9 9 9

4 4
6 4 2 1

4 3
10 3 830 14

2 1
3 1

Output
YES
YES
YES
YES
NO

Solution: for any K >= 2, we can always sort the array by reversing subarrays of length K. This is because we can always swap adjacent elements by reversing a subarray of length 2, and we can move elements around to their correct positions. else if k == 1, we can only reverse subarrays of length 1, which means we cannot change the order of the elements at all. Therefore, the array can only be sorted if it is already sorted in non-decreasing order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSortBoxes(int n, int k, vector<int> &boxes)
    {
        if (k == 1)
        {
            // If k is 1, we can only reverse subarrays of length 1, so the array must already be sorted
            for (int i = 1; i < n; i++)
            {
                if (boxes[i] < boxes[i - 1])
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            // If k >= 2, we can always sort the array
            return true;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    Solution solution;
    while (testCases--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> boxes(n);
        for (int &box : boxes)
        {
            cin >> box;
        }

        cout << (solution.canSortBoxes(n, k, boxes) ? "YES" : "NO") << '\n';
    }

    return 0;
}