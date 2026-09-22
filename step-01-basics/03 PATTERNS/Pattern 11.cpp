#include <iostream>
using namespace std;

// Print alternating 1 and 0 in a triangle.
int main() {
    int n;
    cin >> n;
    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= row; ++col) cout << ((row + col) % 2) << ' ';
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
