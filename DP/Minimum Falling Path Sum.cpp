//https://leetcode.com/problems/minimum-falling-path-sum/description/

class Solution {
public:
    
    int solve(int row, int col, vector<vector<int>>& matrix,vector<vector<int>>&dp) {
        // Base case
        if (col < 0 || col >= matrix[0].size()) {
            return INT_MAX; 
        }
        if (row == matrix.size() - 1) {
            return matrix[row][col];
        }
        if (dp[row][col] != INT_MIN) {//WHY INT_MIN;because -1 can conflict if matrix can contain -1 as valid values.because it contains negative values.
        
            return dp[row][col];
        }
        
        // Recursive step
        int m1 = solve(row + 1, col + 1, matrix,dp);
        int m2 = solve(row + 1, col - 1, matrix,dp);
        int m3 = solve(row + 1, col, matrix,dp);
        
        return dp[row][col] = matrix[row][col] + min({m1, m2, m3});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minPathSum = INT_MAX;
        
       vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        
        for (int col = 0; col < matrix[0].size(); ++col) {
            minPathSum = min(minPathSum, solve(0, col, matrix,dp));
        }
        
        return minPathSum;
    }
};