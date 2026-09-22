#include <iostream>
using namespace std;

// Print rows containing the same alphabet character.
int main() {
    int n;
    cin >> n;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col <= row; ++col) cout << char('A' + row);
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
