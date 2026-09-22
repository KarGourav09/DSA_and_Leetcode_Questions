#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    if (n <= 1) { cout << false; return 0; }
    int sum = 1;
    for (int divisor = 2; divisor * divisor <= n; ++divisor)
        if (n % divisor == 0) sum += divisor + (divisor * divisor == n ? 0 : n / divisor);
    cout << (sum == n);
}
// Time: O(sqrt(n)), space: O(1).
