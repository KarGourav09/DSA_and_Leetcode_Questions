#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() { string text; getline(cin, text); reverse(text.begin(), text.end()); cout << text; }
// Preserves spaces and punctuation. Time: O(n), space: O(1) auxiliary.
