#include <iostream>
#include <vector>
using namespace std;

long long sumFrom(const vector<int> &values, int index) { return index == static_cast<int>(values.size()) ? 0 : values[index] + sumFrom(values, index + 1); }
int main() { int n; cin >> n; vector<int> values(n); for (int &value : values) cin >> value; cout << sumFrom(values, 0); }
// Time: O(n), stack space: O(n).
