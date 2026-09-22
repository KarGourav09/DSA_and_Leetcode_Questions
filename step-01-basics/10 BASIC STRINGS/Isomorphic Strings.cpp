#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    if (a.size() != b.size()) { cout << false; return 0; }
    unordered_map<char, char> forward, backward; bool valid = true;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        if ((forward.count(a[i]) && forward[a[i]] != b[i]) || (backward.count(b[i]) && backward[b[i]] != a[i])) valid = false;
        forward[a[i]] = b[i]; backward[b[i]] = a[i];
    }
    cout << valid;
}
// Time: average O(n), space: O(n).
