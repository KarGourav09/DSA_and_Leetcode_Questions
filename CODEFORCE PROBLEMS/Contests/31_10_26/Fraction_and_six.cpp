/*A. Fraction and Six
time limit per test1 second
memory limit per test256 megabytes
You are given two strings p
 and q
, consisting of lowercase English letters.

Interpret the string p
 as the product of variables written in the numerator of a fraction, and the string q
 as the product of variables written in the denominator. Each character represents a variable.

Since multiplication is commutative, the variables in both the numerator and the denominator may be reordered arbitrarily. In addition, any variable that appears in both the numerator and the denominator may be cancelled. Note that a single occurrence of a variable in the denominator can only cancel exactly one occurrence of that variable in the numerator and vice versa.

Determine whether it is possible to simplify the fraction so that the resulting expression is exactly equal to the string six
. In other words, after performing any number of cancellations and rearrangements, the remaining variables in the numerator must form the string six
, and no variables may remain in the denominator.

For example, if p=sinx
 and q=n
, then the variable n
 can be cancelled, leaving six
 in the numerator.


Input
The first line of the input contains a single integer t
 (1≤t≤100
) — the number of test cases. The description of each test case follows.

The first line of each test case contains two integers n
 and m
 (1≤n,m≤100
) — the lengths of the strings p
 and q
, respectively.

The second line of each test case contains a string p
 denoting the numerator of the fraction. It is guaranteed that the length of the string p
 is equal to n
 and that it contains only lowercase English letters.

The third line of each test case contains a string q
 denoting the denominator of the fraction. It is guaranteed that the length of the string q
 is equal to m
 and that it contains only lowercase English letters.

Output
For each test case, print "YES" if you can simplify the fraction so that the resulting expression is exactly equal to the string six
 and "NO" otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

Example
InputCopy
5
4 1
sinx
n
6 7
xixsms
mixsxim
8 5
fixtures
frute
3 3
abc
def
5 10
sixty
codeforces
OutputCopy
YES
NO
YES
NO
NO
Note
In the first test case, the variable n appears in both the numerator and the denominator, so it can be cancelled. The remaining variables in the numerator are s, i, and x, which can be reordered to obtain six.

In the second test case, after cancelling all possible common variables, the numerator contains only s while the denominator contains only mi. Therefore, the fraction cannot be simplified to six.

In the third test case, the variables f, r, u, t, and e can be cancelled from both sides. The remaining variables in the numerator are s, i, and x, which can be reordered to form six.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string p, string q){
        for(int i = 0; i < q.size(); i++){
            for(int j = 0; j < p.size(); j++){
                if(q[i] == p[j]){
                    p.erase(j, 1);
                    break;
                }
            }
            
        }
        sort(p.begin(), p.end());
        cout << (p == "six" ? "YES" : "NO") << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    Solution solution;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string p, q;
        cin >> p >> q;
        solution.solve(p, q);
    }

    return 0;
}