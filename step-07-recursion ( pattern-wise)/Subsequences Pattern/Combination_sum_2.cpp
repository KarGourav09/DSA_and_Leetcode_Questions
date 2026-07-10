/*40. Combination Sum II, Medium
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

Solution: We will define a recursive function that will take the following parameters:
1. The current index in the candidates array.
2. The current combination of numbers that we have selected.
3. The remaining target sum that we need to achieve.
4. The original candidates array.
then if the sum is equal to the target, we will add the current combination to the result set. If the sum exceeds the target, we will return from the function. We will also skip duplicate numbers in the candidates array to avoid duplicate combinations in the result set. Finally, we will sort the candidates array before starting the recursion to ensure that duplicates are adjacent and can be easily skipped.

time: O(2^n) where n is the number of candidates, as we are exploring all possible combinations. The space complexity is O(n) for the recursion stack and the space used to store the combinations.
space: O(n) for the recursion stack and the space used to store the combinations.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        recurse(0, candidates, target, current, result);
        return result;
    }

private:
    void recurse(int index, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result) {
        if(target == 0){
            result.push_back(current);
            return;
        }

        if(index == candidates.size() || target < 0){
            return;
        }

        // Include the current element
        current.push_back(candidates[index]);
        recurse(index + 1, candidates, target - candidates[index], current, result);
        current.pop_back();

        // Skip duplicates
        while(index + 1 < candidates.size() && candidates[index] == candidates[index + 1]){
            index++;
        }

        // Exclude the current element
        recurse(index + 1, candidates, target, current, result);
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result = solution.combinationSum2(candidates, target);
    
    cout << "Unique combinations that sum to " << target << ":\n";
    for (const auto& combination : result) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i < combination.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
    }
    
    return 0;
}