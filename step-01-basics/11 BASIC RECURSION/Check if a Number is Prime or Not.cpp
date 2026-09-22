#include <iostream>
using namespace std;

bool prime(int n, int divisor) { if (n < 2) return false; if (1LL * divisor * divisor > n) return true; return n % divisor != 0 && prime(n, divisor + 1); }
int main() { int n; cin >> n; cout << prime(n, 2); }
// Time: O(sqrt(n)), stack space: O(sqrt(n)).
