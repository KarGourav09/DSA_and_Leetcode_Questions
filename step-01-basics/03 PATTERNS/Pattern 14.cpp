#include <iostream>
using namespace std;

// Print alphabet rows A, AB, ABC, ...
int main() {
    int n;
    cin >> n;
    for (int row = 1; row <= n; ++row) {
        for (int col = 0; col < row; ++col) cout << char('A' + col);
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
