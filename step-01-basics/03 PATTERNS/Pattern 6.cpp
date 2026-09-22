#include <iostream>
using namespace std;

// Print a decreasing triangle of numbers 1..row length.
int main() {
    int n;
    cin >> n;
    for (int row = n; row >= 1; --row) {
        for (int value = 1; value <= row; ++value) cout << value << ' ';
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
