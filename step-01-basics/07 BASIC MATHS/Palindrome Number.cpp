#include <iostream>
using namespace std;

int main() {
    long long n; cin >> n;
    if (n < 0) { cout << false; return 0; }
    long long original = n, reversed = 0;
    while (n) { reversed = reversed * 10 + n % 10; n /= 10; }
    cout << (original == reversed);
}
// Time: O(number of digits), space: O(1).
