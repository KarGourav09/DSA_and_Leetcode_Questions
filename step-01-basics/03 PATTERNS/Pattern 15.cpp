#include <iostream>
using namespace std;

// Print decreasing alphabet rows.
int main() {
    int n;
    cin >> n;
    for (int row = n; row >= 1; --row) {
        for (int col = 0; col < row; ++col) cout << char('A' + col);
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
