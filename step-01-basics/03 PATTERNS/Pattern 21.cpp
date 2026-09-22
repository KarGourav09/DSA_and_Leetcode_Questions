#include <iostream>
using namespace std;

// Print a hollow square with both diagonals.
int main() {
    int n;
    cin >> n;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            bool border = row == 0 || row == n - 1 || col == 0 || col == n - 1;
            bool diagonal = row == col || row + col == n - 1;
            cout << (border || diagonal ? '*' : ' ');
        }
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
