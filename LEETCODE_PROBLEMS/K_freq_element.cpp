/*347. Top K Frequent Elements, Medium
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.


Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

Solution: 1. make an vector of pairs (int, int) to store the frequency of each element in the array. 
          2. sort the vector of pairs in descending order based on the frequency. 
          3. return the first k elements from the sorted vector.

          time: O(n log n), where n is the length of the input array.
          Space: O(n), since we are using a vector of pairs to store the frequency of each element in the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<pair<int, int>> SortByFreq(vector<pair<int, int>>& freq) {
        sort(freq.begin(), freq.end(), 
        [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        return freq;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> freq;

        for(int i = 0; i < nums.size(); i++) {
            bool found = false;
            for (int j = 0; j < freq.size(); j++) {
                if (freq[j].first == nums[i]) {
                    freq[j].second++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                freq.push_back(make_pair(nums[i], 1));
            }
        }

        freq = SortByFreq(freq);
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freq[i].first);
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = solution.topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent elements: "; // Output: 1
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}