#include <iostream>
#include <vector>
using namespace std;

bool sortedFrom(const vector<int> &values, int index) { return index + 1 >= static_cast<int>(values.size()) || (values[index] <= values[index + 1] && sortedFrom(values, index + 1)); }
int main() { int n; cin >> n; vector<int> values(n); for (int &value : values) cin >> value; cout << sortedFrom(values, 0); }
// Non-decreasing check. Time: O(n), stack space: O(n).
