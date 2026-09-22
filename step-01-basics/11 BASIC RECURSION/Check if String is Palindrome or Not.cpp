#include <iostream>
#include <string>
using namespace std;

bool palindrome(const string &text, int left, int right) { return left >= right || (text[left] == text[right] && palindrome(text, left + 1, right - 1)); }
int main() { string text; getline(cin, text); cout << palindrome(text, 0, static_cast<int>(text.size()) - 1); }
// Time: O(n), stack space: O(n).
