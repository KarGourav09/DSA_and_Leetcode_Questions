#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n; cin >> n; vector<string> words(n); for (string &word : words) cin >> word;
    string prefix = n ? words[0] : "";
    for (int i = 1; i < n; ++i) {
        int length = 0; while (length < static_cast<int>(prefix.size()) && length < static_cast<int>(words[i].size()) && prefix[length] == words[i][length]) ++length;
        prefix.resize(length);
    }
    cout << prefix;
}
// Time: O(total input characters), space: O(1) auxiliary.
