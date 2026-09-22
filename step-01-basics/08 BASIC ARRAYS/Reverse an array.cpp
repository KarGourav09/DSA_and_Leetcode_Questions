#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() { int n; cin >> n; vector<int> values(n); for (int &value : values) cin >> value; reverse(values.begin(), values.end()); for (int value : values) cout << value << ' '; }
// Time: O(n), auxiliary space: O(1) beyond the input array.
