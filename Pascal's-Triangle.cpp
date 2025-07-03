class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1);  // Create a row with (i + 1) elements
            row[0] = row[i] = 1;     // First and last elements are 1

            // Fill the middle elements
            for (int j = 1; j < i; ++j) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }

            result.push_back(row);  // Add the row to the result
        }

        return result;
    }
};
