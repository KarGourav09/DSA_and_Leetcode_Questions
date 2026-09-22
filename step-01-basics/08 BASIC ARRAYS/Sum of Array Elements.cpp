#include <iostream>
using namespace std;

int main() { int n; cin >> n; long long sum = 0, value; for (int i = 0; i < n; ++i) { cin >> value; sum += value; } cout << sum; }
// Time: O(n), space: O(1).
