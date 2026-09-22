#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    long long n; cin >> n; n = llabs(n);
    int largest = 0;
    do { largest = max(largest, static_cast<int>(n % 10)); n /= 10; } while (n);
    cout << largest;
}
// Time: O(number of digits), space: O(1).
