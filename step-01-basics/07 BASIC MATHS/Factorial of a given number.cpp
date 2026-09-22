#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    if (n < 0) { cout << "undefined"; return 0; }
    unsigned long long answer = 1;
    for (int value = 2; value <= n; ++value) answer *= value;
    cout << answer;
}
// Time: O(n), space: O(1). The integer type limits the supported n.
