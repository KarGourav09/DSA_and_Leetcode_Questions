#include <iostream>
using namespace std;

int main() { int n, count = 0; cin >> n; for (int i = 0, value; i < n; ++i) { cin >> value; count += value % 2 != 0; } cout << count; }
// Time: O(n), space: O(1).
