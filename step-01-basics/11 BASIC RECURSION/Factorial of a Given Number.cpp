#include <iostream>
using namespace std;

unsigned long long factorial(int n) { return n <= 1 ? 1 : static_cast<unsigned long long>(n) * factorial(n - 1); }
int main() { int n; cin >> n; if (n < 0) cout << "undefined"; else cout << factorial(n); }
// Time: O(n), stack space: O(n).
