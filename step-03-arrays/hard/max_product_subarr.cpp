/*152. Maximum Product Subarray,Medium
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.

Solution: We can use Kadane's algorithm to solve this problem efficiently. The idea is to iterate through the array and keep track of the maximum product of the subarray that ends at the current index. We also keep track of the overall maximum product found so far. However, since the product can become negative, we also need to keep track of the minimum product at each step, as it can become the maximum product if multiplied by a negative number.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;

        int max_product = nums[0];
        int min_product = nums[0];
        int result = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            int current = nums[i];
            if(current < 0)
                swap(max_product, min_product);

            max_product = max(current, max_product * current);
            min_product = min(current, min_product * current);

            result = max(result, max_product);
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,3,-2,4};
    cout << s.maxProduct(nums) << endl; // Output: 6

    nums = {-2,0,-1};
    cout << s.maxProduct(nums) << endl; // Output: 0

    return 0;
}


/*
alternative solution:
int n = nums.size();
        
        long long product = nums[0];
        long long maxProduct = nums[0];


        if(n == 1)
            return nums[0];
        else if(n == 2)
            return max(nums[0], max(nums[1], nums[0] * nums[1]));

        for(int i = 0; i < n; i++)
        {
            product = nums[i];

            for(int j = i + 1; j < n; j++)
            {
                product *= nums[j];

                maxProduct = max(product, maxProduct);
            }
        }
        return maxProduct;
*/