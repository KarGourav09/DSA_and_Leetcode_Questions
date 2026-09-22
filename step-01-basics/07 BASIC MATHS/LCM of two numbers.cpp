#include <iostream>
#include <cstdlib>
using namespace std;

long long greatestCommonDivisor(long long a, long long b) {
	while (b != 0) {
		long long remainder = a % b;
		a = b;
		b = remainder;
	}
	return a < 0 ? -a : a;
}

int main() { long long a, b; cin >> a >> b; if (a == 0 || b == 0) cout << 0; else cout << llabs(a / greatestCommonDivisor(a, b) * b); }
// Time: O(log(min(|a|, |b|))), space: O(1).
