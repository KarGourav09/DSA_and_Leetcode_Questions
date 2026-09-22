#include <iostream>
using namespace std;

// Print a centered diamond.
int main() {
    int n;
    cin >> n;
    for (int row = 1; row <= 2 * n - 1; ++row) {
        int width = row <= n ? row : 2 * n - row;
        int spaces = n - width;
        for (int i = 0; i < spaces; ++i) cout << ' ';
        for (int i = 0; i < 2 * width - 1; ++i) cout << '*';
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
