class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        
        int row_start = 0, row_end = n - 1;
        int col_start = 0, col_end = m - 1;

        while (row_start <= row_end && col_start <= col_end) {
           
            for (int j = col_start; j <= col_end; j++) {
                ans.push_back(matrix[row_start][j]);
            }
            row_start++;

            // Traverse down
            for (int i = row_start; i <= row_end; i++) {
                ans.push_back(matrix[i][col_end]);
            }
            col_end--;

            // Traverse left
            if (row_start <= row_end) {  // Ensure row is still valid
                for (int j = col_end; j >= col_start; j--) {
                    ans.push_back(matrix[row_end][j]);
                }
                row_end--;
            }

            // Traverse up
            if (col_start <= col_end) {  // Ensure column is still valid
                for (int i = row_end; i >= row_start; i--) {
                    ans.push_back(matrix[i][col_start]);
                }
                col_start++;
            }
        }
        return ans;
    }
};
