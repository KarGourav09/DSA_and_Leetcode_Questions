#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseArray(vector<int> &values, int left, int right) { if (left >= right) return; swap(values[left], values[right]); reverseArray(values, left + 1, right - 1); }
int main() { int n; cin >> n; vector<int> values(n); for (int &value : values) cin >> value; reverseArray(values, 0, n - 1); for (int value : values) cout << value << ' '; }
// Time: O(n), stack space: O(n).
