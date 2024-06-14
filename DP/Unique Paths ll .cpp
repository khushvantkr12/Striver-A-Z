//https://leetcode.com/problems/unique-paths-ii/description/

class Solution {
public:
    int solve(int i, int j, int p, int q, vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp) {
        // Base condition
        if (i == p && j == q) {
            return 1;
        }
       if (i > p || j > q || obstacleGrid[i][j] == 1) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int m1 = 0, m2 = 0;
       
            m1 = solve(i + 1, j, p, q, obstacleGrid,dp);
            m2 = solve(i, j + 1, p, q, obstacleGrid,dp);
        

        return dp[i][j]=m1 + m2;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int p = obstacleGrid.size();
        int q = obstacleGrid[0].size();
        vector<vector<int>>dp(p+1,vector<int>(q+1,-1));
        if(obstacleGrid[p-1][q-1]==1){
            return 0;
        }
        return solve(0, 0, p - 1, q - 1, obstacleGrid,dp);
    }
};

