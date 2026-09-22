#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<bool> prime(max(0, n + 1), true);
    if (n >= 0) prime[0] = false;
    if (n >= 1) prime[1] = false;
    for (int value = 2; 1LL * value * value <= n; ++value)
        if (prime[value]) for (long long multiple = 1LL * value * value; multiple <= n; multiple += value) prime[multiple] = false;
    int count = 0; for (bool value : prime) count += value;
    cout << count;
}
// Time: O(n log log n), space: O(n).
