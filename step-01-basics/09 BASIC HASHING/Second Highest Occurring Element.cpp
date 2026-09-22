#include <iostream>
#include <map>
#include <climits>
using namespace std;

int main() {
    int n; cin >> n; map<int, int> frequency;
    for (int i = 0, value; i < n; ++i) { cin >> value; ++frequency[value]; }
    int highest = 0, second = 0, answer = INT_MAX;
    for (map<int, int>::const_iterator entry = frequency.begin(); entry != frequency.end(); ++entry) {
        if (entry->second > highest) { second = highest; highest = entry->second; }
        else if (entry->second > second) second = entry->second;
    }
    for (map<int, int>::const_iterator entry = frequency.begin(); entry != frequency.end(); ++entry)
        if (entry->second == second && second > 0) answer = min(answer, entry->first);
    if (answer != INT_MAX) cout << answer; else cout << "no second frequency";
}
// Time: O(n log n), space: O(n).
