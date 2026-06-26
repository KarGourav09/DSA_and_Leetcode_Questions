/*Count Number of Substrings
Problem Statement: You are given a string s and a positive integer k.
Return the number of substrings that contain exactly k distinct characters.

Examples
Example 1:
Input:
 s = "pqpqs", k = 2  
Output:
 7  
Explanation:
  All substrings with exactly 2 distinct characters:  
"pq", "pqp", "pqpq", "qp", "qpq", "pqs", "qs"  
Total = 7.

Solution: 1. Define a helper function atMostKDistinct(s, k):
          2. Use a sliding window with two pointers (left and right) and a frequency map.
          3. Expand the window by moving the right pointer and count characters.
          4. If the count of distinct characters exceeds k, shrink the window by moving the left pointer.
          5. For each valid window, add (right - left + 1) to the result.
          6. To find substrings with exactly k distinct characters, calculate:
          7. atMostKDistinct(s, k) - atMostKDistinct(s, k-1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int AtMostDistinct(string s, int k){
        unordered_map<char, int> mp;
        int left = 0, count = 0;
        for(int right = 0; right < s.size(); right++){
            mp[s[right]]++;
            while(mp.size() > k){
                mp[s[left]]--;
                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }

    int substrCount(string s, int k) {
        return AtMostDistinct(s, k) - AtMostDistinct(s, k - 1);
    }
};

int main() {
    Solution solution;
    string s = "pqpqs";
    int k = 2;
    cout << solution.substrCount(s, k) << endl; // Output: 7

    string s2 = "abcba";
    int k2 = 2;
    cout << solution.substrCount(s2, k2) << endl; // Output: 7

    string s3 = "aa";
    int k3 = 1;
    cout << solution.substrCount(s3, k3) << endl; // Output: 3
    
    return 0;
}