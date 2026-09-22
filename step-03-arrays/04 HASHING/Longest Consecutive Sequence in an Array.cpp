#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n; unordered_set<int> values;
    for (int i = 0, value; i < n; ++i) { cin >> value; values.insert(value); }
    int answer = 0;
    for (int value : values) if (!values.count(value - 1)) {
        int current = value;
        while (values.count(current)) ++current;
        answer = max(answer, current - value);
    }
    cout << answer;
}
// Average time: O(n), space: O(n).
