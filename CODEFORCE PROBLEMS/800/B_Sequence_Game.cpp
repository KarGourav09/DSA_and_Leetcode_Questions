/*## B. Sequence Game

**Time Limit:** 2 seconds
**Memory Limit:** 256 megabytes

Tema and Vika play a game involving sequences of positive integers.

Vika starts by creating a sequence `a` of length `m`. She then derives a new sequence `b` by:
1. Including `a1`.
2. Subsequently including `ai` (for `2 <= i <= m`) only if `a(i-1) <= ai`.
The length of this new sequence `b` is `n`.

For example, if `a = [4, 3, 2, 6, 3, 3]`, then `b` would be `[4, 6, 3]`.

Vika gives Tema the sequence `b`, and Tema must guess a possible original sequence `a`. Tema needs help finding *any* valid sequence `a`. The length of the output sequence `a` should not exceed twice the length of `b`.

**Input:**
The input begins with an integer `t` (1 <= `t` <= 10^4), indicating the number of test cases.
Each test case consists of two lines:
1. An integer `n` (1 <= `n` <= 2 * 10^5), the length of sequence `b`.
2. `n` integers `b1, b2, ..., bn` (1 <= `bi` <= 10^9), the elements of sequence `b`.
The sum of `n` over all test cases does not exceed 2 * 10^5.

**Output:**
For each test case, output two lines:
1. An integer `m`, the length of the reconstructed sequence `a` (`n <= m <= 2 * n`).
2. `m` integers `a1, a2, ..., am` (1 <= `ai` <= 10^9), representing a possible original sequence `a`.

Any valid sequence `a` is acceptable.

**Example:**

**Input:**
```
6
3
4 6 3
3
1 2 3
5
1 7 9 5 7
1
144
2
1 1
5
1 2 2 1 1
```

**Output:**
```
6
4 3 2 6 3 3
3
1 2 3
6
1 7 9 3 5 7
1
144
2
1 1
6
1 2 2 1 1 1

Solution: 
```*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> solve(vector<int> b, int n){
        vector<int> a;
        a.push_back(b[0]);
        for(int i = 1; i < n; i++){
            if(b[i] < b[i-1]){
                a.push_back(1);
            }
            a.push_back(b[i]);
        }
        return a;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        Solution sol;
        vector<int> a = sol.solve(b, n);
        cout << a.size() << "\n";
        for(int value : a){
            cout << value << " ";
        }
        cout << "\n";
    }
    return 0;
}