#include <iostream>
#include <cstdlib>
using namespace std;

int digitSum(long long n) { n = llabs(n); return n < 10 ? static_cast<int>(n) : static_cast<int>(n % 10) + digitSum(n / 10); }
int main() { long long n; cin >> n; cout << digitSum(n); }
// Time: O(number of digits), stack space: O(number of digits).
