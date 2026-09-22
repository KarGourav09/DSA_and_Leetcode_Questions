#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string text; cin >> text; map<char, int> frequency; for (char c : text) ++frequency[c];
    vector<pair<char, int>> items(frequency.begin(), frequency.end());
    sort(items.begin(), items.end(), [](auto left, auto right) { if (left.second != right.second) return left.second > right.second; return left.first < right.first; });
    for (vector<pair<char, int> >::const_iterator item = items.begin(); item != items.end(); ++item)
        cout << string(item->second, item->first);
}
// Time: O(n + u log u), where u is the number of distinct characters; space: O(u).
