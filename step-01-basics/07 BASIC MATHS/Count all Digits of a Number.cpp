#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    long long n; cin >> n;
    n = llabs(n);
    if (n == 0) { cout << 1; return 0; }
    int digits = 0;
    while (n) { ++digits; n /= 10; }
    cout << digits;
}
// Time: O(log10(|n|)), space: O(1).
