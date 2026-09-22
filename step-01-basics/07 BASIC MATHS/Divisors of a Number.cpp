#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    if (n <= 0) return 0;
    for (int divisor = 1; divisor * divisor <= n; ++divisor) if (n % divisor == 0) {
        cout << divisor << ' ';
        if (divisor != n / divisor) cout << n / divisor << ' ';
    }
}
// Finds divisor pairs in O(sqrt(n)); sort the output if ordered divisors are required.
