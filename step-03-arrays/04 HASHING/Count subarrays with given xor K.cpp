#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, target; cin >> n >> target;
    unordered_map<int, long long> frequency; frequency[0] = 1;
    int prefix = 0; long long answer = 0;
    for (int i = 0, value; i < n; ++i) { cin >> value; prefix ^= value; answer += frequency[prefix ^ target]; ++frequency[prefix]; }
    cout << answer;
}
// Prefix XOR identity gives the required prior key. Average time: O(n), space: O(n).
