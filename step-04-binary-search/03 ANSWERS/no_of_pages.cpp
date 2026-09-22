/*Allocate Minimum Number of Pages
Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

Each student gets at least one book.
Each book should be allocated to only one student.
Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1

Example 1:
Input Format: n = 4, m = 2, arr[] = {12, 34, 67, 90}
Result: 113
Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& arr, int maxPages) {
        int studentCount = 1; // Start with one student
        int currentPages = 0;

        for (int pages : arr) {
            if (pages > maxPages) {
                return -1; // If a single book has more pages than maxPages, allocation is not possible
            }
            if (currentPages + pages > maxPages) {
                studentCount++; // Allocate to next student
                currentPages = pages; // Start counting pages for the new student
            } else {
                currentPages += pages; // Add pages to the current student's total
            }
        }
        return studentCount;
    }

    int allocateBooks(vector<int>& arr, int m) {
        int low = 0, high = 0;
        for (int pages : arr) {
            high += pages; // Total pages if one student reads all books
        }
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int requiredStudents = countStudents(arr, mid);

            if (requiredStudents == -1 || requiredStudents > m) {
                low = mid + 1; // Need more pages per student
            } else {
                result = mid; // Update result and try for a smaller maximum
                high = mid - 1; // Try for a smaller maximum
            }
        }
        return result;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.allocateBooks(arr, m) << endl;

    return 0;
}