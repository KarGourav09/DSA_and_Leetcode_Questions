/*K-th Element of two sorted arrays
Problem Statement: Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.

Example 1:
Input:
 a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5  
Output:
 6  
Explanation:
 The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
 */

 #include<iostream>
 #include<vector>

 using namespace std;

int KthElement (vector<int> &arr1,vector<int> &arr2,int m, int n, int k)
{
    vector<int> result;

    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }
    // If there are remaining elements in arr1
    while (i < m) {
        result.push_back(arr1[i]);
        i++;
    }
    // If there are remaining elements in arr2
    while (j < n) {
        result.push_back(arr2[j]);
        j++;
    }

    if (k > 0 && k <= result.size()) {
        cout << "The " << k << "-th element is: " << result[k - 1] << endl;
    } else {
        cout << "Invalid value of k" << endl;
    }
}

int main()
{
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int m = arr1.size();
    int n = arr2.size();
    int k = 5;

    KthElement(arr1, arr2, m, n, k);

    return 0;
}