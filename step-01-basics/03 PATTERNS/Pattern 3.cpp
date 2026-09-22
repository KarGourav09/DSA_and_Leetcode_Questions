#include <iostream>
using namespace std;

// Print increasing rows of numbers 1..row.
int main() {
    int n;
    cin >> n;
    for (int row = 1; row <= n; ++row) {
        for (int value = 1; value <= row; ++value) cout << value << ' ';
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
