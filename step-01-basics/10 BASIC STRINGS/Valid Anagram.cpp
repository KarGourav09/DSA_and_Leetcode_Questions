#include <iostream>
#include <string>
#include <array>
using namespace std;

int main() {
    string a, b; cin >> a >> b; array<int, 256> count{};
    if (a.size() != b.size()) { cout << false; return 0; }
    for (unsigned char c : a) ++count[c]; for (unsigned char c : b) --count[c];
    bool valid = true; for (int value : count) valid = valid && value == 0; cout << valid;
}
// ASCII anagram check. Time: O(n), space: O(1).
