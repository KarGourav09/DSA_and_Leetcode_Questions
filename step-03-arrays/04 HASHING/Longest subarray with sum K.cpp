#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n; long long target; cin >> n >> target;
    unordered_map<long long, int> firstIndex; firstIndex[0] = -1;
    long long prefix = 0; int answer = 0;
    for (int index = 0, value; index < n; ++index) {
        cin >> value; prefix += value;
        if (firstIndex.count(prefix - target)) answer = max(answer, index - firstIndex[prefix - target]);
        if (!firstIndex.count(prefix)) firstIndex[prefix] = index;
    }
    cout << answer;
}
// Works with negative values. Average time: O(n), space: O(n).
