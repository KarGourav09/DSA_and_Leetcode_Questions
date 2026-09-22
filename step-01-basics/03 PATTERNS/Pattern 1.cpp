#include <iostream>
using namespace std;

// Print an N by N square of stars.
int main() {
    int n;
    cin >> n;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) cout << "* ";
        cout << '\n';
    }
}
// Time: O(n^2), extra space: O(1).
