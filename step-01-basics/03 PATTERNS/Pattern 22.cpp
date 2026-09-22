#include <iostream>
using namespace std;

// Print concentric layers of descending integers.
int main() {
    int n;
    cin >> n;
    int size = 2 * n - 1;
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            int distance = min(min(row, col), min(size - 1 - row, size - 1 - col));
            cout << n - distance << ' ';
        }
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
