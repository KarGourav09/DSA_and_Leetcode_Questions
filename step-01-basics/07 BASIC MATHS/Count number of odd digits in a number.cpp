#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    long long n; cin >> n; n = llabs(n);
    int answer = 0;
    if (n == 0) cout << 0;
    while (n) { answer += (n % 10) % 2; n /= 10; }
    cout << answer;
}
// Time: O(number of digits), space: O(1).
