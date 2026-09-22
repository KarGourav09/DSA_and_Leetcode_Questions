#include <iostream>
#include <string>
using namespace std;

int main() {
    string digits; cin >> digits;
    int end = static_cast<int>(digits.size()) - 1;
    while (end >= 0 && (digits[end] - '0') % 2 == 0) --end;
    if (end >= 0) cout << digits.substr(0, end + 1);
}
// The largest odd prefix ends at the rightmost odd digit. Time: O(n), space: O(n) for output.
