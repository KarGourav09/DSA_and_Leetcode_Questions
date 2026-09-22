#include <iostream>
using namespace std;

long long fibonacci(int n) { return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2); }
int main() { int n; cin >> n; if (n < 0) cout << "undefined"; else cout << fibonacci(n); }
// Direct recursion: O(2^n) time and O(n) stack. Memoization reduces time to O(n).
