#include <iostream>
#include <string>
using namespace std;

int main() {
    string text; getline(cin, text); bool palindrome = true;
    for (int left = 0, right = static_cast<int>(text.size()) - 1; left < right; ++left, --right)
        if (text[left] != text[right]) palindrome = false;
    cout << palindrome;
}
// Exact, case-sensitive check. Time: O(n), space: O(1).
