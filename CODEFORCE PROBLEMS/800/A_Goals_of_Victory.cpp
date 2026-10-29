/*A. Goals of Victory

**Problem Statement:** In a football tournament with *n* teams, each team plays every other team once. The result of each match is recorded as the goals scored by both teams. A team's "efficiency" is calculated as the sum of goals it scored minus the sum of goals scored by its opponents across all matches. After the tournament, the efficiencies of *n-1* teams are known. The task is to determine the efficiency of the missing team, which is guaranteed to be uniquely determinable.

**Input:**
*   **t:** The number of test cases (1 ≤ t ≤ 500).
*   For each test case:
    *   **n:** The number of teams (2 ≤ n ≤ 100).
    *   **a1, a2, ..., an-1:** The efficiencies of *n-1* teams (-100 ≤ ai ≤ 100).

**Output:**
*   For each test case, output the efficiency of the missing team.

**Example:**

**Input:**
```
2
4
3 -4 5
11
-30 12 -57 7 0 -81 -68 41 -89 0
```

**Output:**
```
-4
265
```

**Note:** The example illustrates a tournament with 4 teams. If the efficiencies of 3 teams are 3, -4, and 5, the efficiency of the 4th team must be -4. This can be derived from the sum of all efficiencies always being zero.*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findMissingEfficiency(int n, vector<int> &efficiencies){
        int totalEfficiency = 0;
        for(int i = 0; i < n - 1; i++){
            totalEfficiency += efficiencies[i];
        }
        return -totalEfficiency;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> efficiencies(n - 1);
        for(int i = 0; i < n - 1; i++){
            cin >> efficiencies[i];
        }
        Solution sol;
        cout << sol.findMissingEfficiency(n, efficiencies) << endl;
    }
    return 0;
}