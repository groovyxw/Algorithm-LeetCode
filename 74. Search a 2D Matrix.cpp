You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
  
  
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0, end = row * col - 1;
        while (start <= end) {
            int mid = start + (end - start)/2;
            int r = mid / col;
            int c = mid % col;
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;

        // int n = matrix.size();
        // int m = matrix[0].size();
        
        // int left = 0, right = n*m - 1;
        // while(left <= right) {
        //     int mid = left + (right - left)/2;
        //     int row = mid / m;
        //     int col = mid % m;
        //     if(matrix[row][col] == target) {
        //         return true;
        //     }else if (matrix[row][col] > target) {
        //         right = mid - 1;
        //     }else {
        //         left = mid + 1;
        //     }
        // }
        // return false;
    }
};
