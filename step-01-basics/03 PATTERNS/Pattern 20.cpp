#include <iostream>
using namespace std;

// Print a hollow diamond border.
int main() {
    int n;
    cin >> n;
    for (int row = 1; row <= 2 * n - 1; ++row) {
        int width = row <= n ? row : 2 * n - row;
        int outer = n - width;
        for (int i = 0; i < outer; ++i) cout << ' ';
        for (int col = 1; col <= 2 * width - 1; ++col)
            cout << (col == 1 || col == 2 * width - 1 ? '*' : ' ');
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
