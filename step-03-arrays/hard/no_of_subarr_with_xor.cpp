/*Count the number of subarrays with given xor K
Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

Examples
Input: A = [4, 2, 2, 6, 4] , k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
*/

#include <iostream>
#include <vector>

using namespace std;

int countSubarrWithXorK(vector<int>& arr, int k)
{
    int count = 0;
    int n = arr.size();
    int xorSum = 0;

    vector<int> prefixXor(n);
    
    for(int i = 0; i < n; i++)
    {
        xorSum ^= arr[i];
        prefixXor[i] = xorSum;
        
        if (xorSum == k) {
            count++;
        }
        
        for(int j = 0; j < i; j++)
        {
            if((xorSum ^ prefixXor[j]) == k) {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    
    int result = countSubarrWithXorK(arr, k);
    cout << "Number of subarrays with XOR " << k << " is: " << result << endl;
    
    return 0;
}