#include <iostream>
using namespace std;

// Print an inverted centered pyramid.
int main() {
    int n;
    cin >> n;
    for (int row = n; row >= 1; --row) {
        for (int space = 0; space < n - row; ++space) cout << ' ';
        for (int star = 0; star < 2 * row - 1; ++star) cout << '*';
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
