/*Union of Two Sorted Arrays
Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.
NOTE: Elements in the union should be in ascending order.

Examples
Input:n = 5,m = 5 arr1[] = {1,2,3,4,5}  arr2[] = {2,3,4,4,5}
Output: {1,2,3,4,5}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5}*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> findUnion (vector<int> arr1, vector<int> arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    if(n == 0 && m == 0)
        return {};

    vector<int> ans;
    int i = 0, j = 0;

    while(i < n && j < m)
    {
        if(arr1[i] < arr2[j])
        {
            if(ans.empty() || ans.back() != arr1[i])
                ans.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i] > arr2[j])
        {
            if(ans.empty() || ans.back() != arr2[j])
                ans.push_back(arr2[j]);
            j++;
        }
        else
        {
            if(ans.empty() || ans.back() != arr1[i])
                ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {2,3,4,4,5};

    vector<int> result = findUnion(arr1, arr2);

    cout << "Union of the two sorted arrays is: ";
    for(int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}