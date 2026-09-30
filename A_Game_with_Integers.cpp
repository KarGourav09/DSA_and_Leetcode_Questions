/*A. Game with Integers
time limit per test1 second
memory limit per test256 megabytes
Vanya and Vova are playing a game. Players are given an integer n
. On their turn, the player can add 1
 to the current integer or subtract 1
. The players take turns; Vanya starts. If after Vanya's move the integer is divisible by 3
, then he wins. If 10
 moves have passed and Vanya has not won, then Vova wins.

Write a program that, based on the integer n
, determines who will win if both players play optimally.

Input
The first line contains the integer t
 (1≤t≤100
) — the number of test cases.

The single line of each test case contains the integer n
 (1≤n≤1000
).

Output
For each test case, print "First" without quotes if Vanya wins, and "Second" without quotes if Vova wins.

Example
InputCopy
6
1
3
5
100
999
1000
OutputCopy
First
Second
First
First
Second
First

Solution: vanya starts first, If n is divisible by 3 then vova will always win because vanya will not be able to make it divisible by 3 in his first move. If n is not divisible by 3, then vanya can always make it divisible by 3 in his first move and win the game. Therefore, the solution is to check if n is divisible by 3 or not. If it is, print "Second", otherwise print "First" as the winner.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string determineWinner(int n) {
        // If n is divisible by 3, Vova wins; otherwise, Vanya wins
        return (n % 3 == 0) ? "Second" : "First";
    }
};

int main() {
    int t;
    cin >> t;

    Solution solution;
    while (t--) {
        int n;
        cin >> n;
        cout << solution.determineWinner(n) << '\n';
    }

    return 0;
}