#include <iostream>
using namespace std;

// Print rows where every value equals the row number.
int main() {
    int n;
    cin >> n;
    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= row; ++col) cout << row << ' ';
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
