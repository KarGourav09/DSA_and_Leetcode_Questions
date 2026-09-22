#include <iostream>
using namespace std;

// Print alphabet rows starting at the row's character.
int main() {
    int n;
    cin >> n;
    for (int row = 0; row < n; ++row) {
        for (int col = row; col < n; ++col) cout << char('A' + col);
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
