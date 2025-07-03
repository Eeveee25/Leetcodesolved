class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();         // number of rows
        int n = matrix[0].size();      // number of columns

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (top <= bottom && left <= right) {
            // 1. Traverse from left to right (top row)
            for (int j = left; j <= right; ++j) {
                result.push_back(matrix[top][j]);
            }
            top++;  // move top boundary down

            // 2. Traverse from top to bottom (right column)
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--;  // move right boundary left

            // 3. Traverse from right to left (bottom row)
            if (top <= bottom) {
                for (int j = right; j >= left; --j) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;  // move bottom boundary up
            }

            // 4. Traverse from bottom to top (left column)
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++;  // move left boundary right
            }
        }

        return result;
    }
};
