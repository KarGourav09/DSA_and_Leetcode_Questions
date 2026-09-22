#include <iostream>
using namespace std;

// Print a continuous number triangle.
int main() {
    int n, value = 1;
    cin >> n;
    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= row; ++col) cout << value++ << ' ';
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
