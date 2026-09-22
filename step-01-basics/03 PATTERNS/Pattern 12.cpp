#include <iostream>
using namespace std;

// Print mirrored number and space halves.
int main() {
    int n;
    cin >> n;
    for (int row = 1; row <= n; ++row) {
        for (int value = 1; value <= row; ++value) cout << value;
        for (int space = 0; space < 2 * (n - row); ++space) cout << ' ';
        for (int value = row; value >= 1; --value) cout << value;
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
