/*Find the row with maximum number of 1's

Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order. Your task is to find the index of the row with the maximum number of ones. Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1

Example 1:
Input Format: n = 3, m = 3, 
mat[] = 
1 1 1
0 0 1
0 0 0
Result: 0
Explanation: The row with the maximum number of ones is 0 (0 - indexed).
*/

#include<iostream>
#include<vector>

using namespace std;

int rowWithMax1s(vector<vector<int>> &mat, int n, int m) {
    int max_row_index = -1; // Initialize to -1 to handle the case when no row has 1s
    int max_ones_count = 0; // To keep track of the maximum number of 1s found

    for (int i = 0; i < n; i++) {
        int count_ones = 0; // Count of 1s in the current row
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                count_ones++;
            }
        }
        // Update max_row_index if the current row has more 1s than the previous maximum
        if (count_ones > max_ones_count) {
            max_ones_count = count_ones;
            max_row_index = i;
        }
    }

    return max_row_index;
}

int main() {
    int n = 3, m = 3;
    vector<vector<int>> mat = {
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    int result = rowWithMax1s(mat, n, m);
    cout << "The index of the row with the maximum number of ones is: " << result << endl;

    return 0;
}