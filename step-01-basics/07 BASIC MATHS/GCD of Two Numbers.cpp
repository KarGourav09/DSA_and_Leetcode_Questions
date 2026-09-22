#include <iostream>
using namespace std;

long long greatestCommonDivisor(long long a, long long b) {
	while (b != 0) {
		long long remainder = a % b;
		a = b;
		b = remainder;
	}
	return a < 0 ? -a : a;
}

int main() { long long a, b; cin >> a >> b; cout << greatestCommonDivisor(a, b); }
// Euclid's algorithm. Time: O(log(min(|a|, |b|))), space: O(1).
