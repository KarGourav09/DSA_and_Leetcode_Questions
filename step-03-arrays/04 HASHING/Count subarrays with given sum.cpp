#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n; long long target; cin >> n >> target;
    unordered_map<long long, long long> frequency; frequency[0] = 1;
    long long prefix = 0, answer = 0;
    for (int i = 0, value; i < n; ++i) { cin >> value; prefix += value; answer += frequency[prefix - target]; ++frequency[prefix]; }
    cout << answer;
}
// Count frequencies, unlike longest-subarray problems. Average time: O(n), space: O(n).
