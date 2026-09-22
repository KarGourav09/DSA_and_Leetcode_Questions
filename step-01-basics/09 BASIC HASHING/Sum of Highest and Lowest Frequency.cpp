#include <iostream>
#include <unordered_map>
#include <limits>
using namespace std;

int main() {
    int n; cin >> n; unordered_map<int, int> frequency;
    for (int i = 0, value; i < n; ++i) { cin >> value; ++frequency[value]; }
    if (frequency.empty()) { cout << 0; return 0; }
    int lowest = numeric_limits<int>::max(), highest = 0;
    for (unordered_map<int, int>::const_iterator entry = frequency.begin(); entry != frequency.end(); ++entry) {
        lowest = min(lowest, entry->second);
        highest = max(highest, entry->second);
    }
    cout << lowest + highest;
}
// Time: average O(n), space: O(n).
