#include <iostream>
using namespace std;

int main() {
    long long n; cin >> n;
    long long answer = 0;
    while (n != 0) { answer = answer * 10 + n % 10; n /= 10; }
    cout << answer;
}
// Time: O(number of digits), space: O(1). Check overflow for fixed-width types.
