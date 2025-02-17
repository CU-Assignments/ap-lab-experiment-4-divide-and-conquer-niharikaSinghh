class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();      // Number of rows
        int n = matrix[0].size();   // Number of columns
        int row = 0, col = n - 1;  // Start from the top-right corner

        // Iterate until the row or column goes out of bounds
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;  // Target found
            } else if (matrix[row][col] < target) {
                row++;  // Move down if the current value is smaller than target
            } else {
                col--;  // Move left if the current value is larger than target
            }
        }
        
        return false;  // Target not found
    }
};
