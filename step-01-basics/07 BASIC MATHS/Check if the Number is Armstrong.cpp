#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n; cin >> n;
    if (n < 0) { cout << false; return 0; }
    long long copy = n; int digits = n == 0 ? 1 : 0;
    while (copy) { ++digits; copy /= 10; }
    copy = n; long long sum = 0;
    do { sum += static_cast<long long>(pow(copy % 10, digits)); copy /= 10; } while (copy);
    cout << (sum == n);
}
// Time: O(digits), space: O(1).
