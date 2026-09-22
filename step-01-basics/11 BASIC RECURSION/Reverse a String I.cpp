#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reverseFrom(string &text, int left, int right) { if (left >= right) return; swap(text[left], text[right]); reverseFrom(text, left + 1, right - 1); }
int main() { string text; getline(cin, text); reverseFrom(text, 0, static_cast<int>(text.size()) - 1); cout << text; }
// Time: O(n), stack space: O(n).
