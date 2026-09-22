#include <iostream>
using namespace std;

// Print a centered alphabet pyramid.
int main() {
    int n;
    cin >> n;
    for (int row = 0; row < n; ++row) {
        for (int space = 0; space < n - row - 1; ++space) cout << ' ';
        for (int col = 0; col <= row; ++col) cout << char('A' + col);
        for (int col = row - 1; col >= 0; --col) cout << char('A' + col);
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
