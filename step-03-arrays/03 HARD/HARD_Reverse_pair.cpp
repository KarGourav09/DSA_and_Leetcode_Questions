/*493. Reverse Pairs, Hard
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int merge(vector<int>&arr,int l,int m,int r){
        int n1=m-l+1,n2=r-m;
        int left[n1],right[n2];
        for(int i=0;i<n1;i++){
            left[i]=arr[l+i];
        }
        for(int i=0;i<n2;i++){
            right[i]=arr[m+1+i];
        }
        
        int cnt=0;
        int i=0,j=0;
        while(i<n1&&j<n2){
            if((long)left[i]>(long)(2*(long)right[j])){
                cnt+=n1-i;
                j++;
            }else{
                i++;
            }
        }
        i=0,j=0;
        int k=0;
        while(i<n1&&j<n2){
            if(left[i]<=right[j]){
                arr[l+k++]=left[i++];
            }else{
                arr[l+k++]=right[j++];
            }
        }
        while(i<n1){
            arr[l+k++]=left[i++];
        }
        while(j<n2){
            arr[l+k++]=right[j++];
        }
        return cnt;
    }
    int mergeSort(vector<int>&arr,int l,int r){
        int ans=0;
        if(l<r){
            int m=l+(r-l)/2;
            ans+=mergeSort(arr,l,m);
            ans+=mergeSort(arr,m+1,r);
            ans+=merge(arr,l,m,r);
        }
        return ans;
    }

    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main()
{
    Solution s;

    vector<int> nums = {1, 3, 2, 3, 1};

    int result = s.reversePairs(nums);

    cout << "Number of reverse pairs: " << result << endl;

    return 0;
}