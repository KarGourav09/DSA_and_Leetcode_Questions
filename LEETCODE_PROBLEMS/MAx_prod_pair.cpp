#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();
        int max_product = INT_MIN;
        vector<int> pair = {-1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && nums[i] + nums[j] == target &&
                    nums[i] > nums[j]) {
                    int current_product = nums[i] * nums[j];
                    if (current_product > max_product) {
                        max_product = current_product;
                        pair = {i, j};
                    }
                }
            }
        }
        return pair;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 7;
    vector<int> result = solution.maxProductPair(nums, target);
    cout << "Indices of the pair with maximum product: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}