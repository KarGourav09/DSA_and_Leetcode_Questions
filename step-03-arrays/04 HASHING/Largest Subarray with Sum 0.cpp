#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n; unordered_map<long long, int> firstIndex; firstIndex[0] = -1;
    long long prefix = 0; int answer = 0;
    for (int index = 0, value; index < n; ++index) {
        cin >> value; prefix += value;
        if (firstIndex.count(prefix)) answer = max(answer, index - firstIndex[prefix]);
        else firstIndex[prefix] = index;
    }
    cout << answer;
}
// Equal prefix sums bound a zero-sum subarray. Average time: O(n), space: O(n).
