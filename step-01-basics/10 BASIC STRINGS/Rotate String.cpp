#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string text; int k; cin >> text >> k;
    if (!text.empty()) { k = (k % text.size() + text.size()) % text.size(); rotate(text.begin(), text.begin() + k, text.end()); }
    cout << text;
}
// Left rotation by k. Time: O(n), space: O(1) auxiliary.
