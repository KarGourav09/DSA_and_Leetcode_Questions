#include <iostream>
#include <map>
using namespace std;

int main() {
    int n; cin >> n; map<int, int> frequency;
    for (int i = 0, value; i < n; ++i) { cin >> value; ++frequency[value]; }
    int answer = 0, best = 0;
    for (map<int, int>::const_iterator entry = frequency.begin(); entry != frequency.end(); ++entry)
        if (entry->second > best) { best = entry->second; answer = entry->first; }
    if (!frequency.empty()) cout << answer;
}
// Tie rule: smallest value wins because map is ordered. Time: O(n log n), space: O(n).
