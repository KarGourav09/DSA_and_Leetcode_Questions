/*49. Group Anagrams, Medium
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store: [Sorted String Key] -> [List of Original Strings]
        unordered_map<string, vector<string>> anagramMap;
        
        for (string s : strs) {
            string key = s; 
            sort(key.begin(), key.end()); // Sorting 'eat' becomes 'aet'
            
            anagramMap[key].push_back(s); // Group the original word under its sorted key
        }
        
        // Collect all grouped vectors from the map into our final result
        vector<vector<string>> result;
        for (auto pair : anagramMap) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    Solution solution;
    vector<vector<string>> grouped = solution.groupAnagrams(strs);
    
    // Printing the grouped anagrams
    cout << "Grouped Anagrams:\n";
    for (const auto& group : grouped) {
        cout << "[ ";
        for (string word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}