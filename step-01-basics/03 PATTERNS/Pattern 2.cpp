#include <iostream>
using namespace std;

// Print a left-aligned increasing triangle.
int main() {
    int n;
    cin >> n;
    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= row; ++col) cout << "* ";
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
