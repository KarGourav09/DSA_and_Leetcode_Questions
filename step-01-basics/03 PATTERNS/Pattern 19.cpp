#include <iostream>
using namespace std;

// Print a hollow inverted and upright star pattern.
int main() {
    int n;
    cin >> n;
    for (int row = n; row >= 1; --row) {
        for (int col = 1; col <= row; ++col) cout << ((row == n || col == 1 || col == row) ? '*' : ' ');
        cout << '\n';
    }
    for (int row = 2; row <= n; ++row) {
        for (int col = 1; col <= row; ++col) cout << ((col == 1 || col == row) ? '*' : ' ');
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
