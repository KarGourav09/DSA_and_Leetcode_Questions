#include <iostream>
using namespace std;

long long sumTo(int n) { return n <= 0 ? 0 : n + sumTo(n - 1); }
int main() { int n; cin >> n; cout << sumTo(n); }
// Time: O(n), stack space: O(n).
