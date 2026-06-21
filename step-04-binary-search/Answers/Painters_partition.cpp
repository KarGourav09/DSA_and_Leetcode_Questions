/*Painter's Partition Problem
Problem Statement: Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.

Example 1:
Input Format: N = 4, boards[] = {5, 5, 5, 5}, k = 2
Result: 10
Explanation: We can divide the boards into 2 equal-sized partitions, so each painter gets 10 units of the board and the total time taken is 10.
*/

#include<iostream>
#include<vector>


using namespace std;

class Solution{
    public:
        int countPainter(vector<int> &boards, int maxBoard){
            int painterCount = 1; // Start with one painter
            int currentBoard = 0;

            for(int i = 0; i < boards.size(); i++){
                if(boards[i] > maxBoard){
                    return -1; // If a single board is longer than maxBoard, allocation is not possible
                }
                if(currentBoard + boards[i] > maxBoard){
                    painterCount++; // Allocate to next painter
                    currentBoard = boards[i]; // Start counting board length for the new painter
                } else {
                    currentBoard += boards[i]; // Add board length to the current painter's total
                }
            }
            return painterCount;
        }

        int painterPartition(vector<int> &boards, int K){

            int low = 0, high = 0;

            for(int i = 0; i < boards.size(); i++){
                high += boards[i]; // Total length if one painter paints all boards
            }
            int result = -1;

            while(low <= high){
                int mid = low + (high - low) / 2;
                int requiredPainters = countPainter(boards, mid);

                if(requiredPainters == -1 || requiredPainters > K){
                    low = mid + 1; // Need more length per painter
                } else {
                    result = mid; // Update result and try for a smaller maximum
                    high = mid - 1; // Try for a smaller maximum
                }
            }
            return result;
        }

};

int main() {
    int N = 4, K = 2;
    vector<int> boards = {5, 5, 5, 5};

    Solution sol;
    int result = sol.painterPartition(boards, K);
    cout << result << endl;

    return 0;
}