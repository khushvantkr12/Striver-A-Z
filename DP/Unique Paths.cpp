//https://leetcode.com/problems/unique-paths/description/
//T.C-O(M*N)

class Solution {
public:
    int solve(int i,int j,int n,int m,  vector<vector<int>>&dp){
        //base condition
      if(i==n && j==m){
        return 1;
      }
    if(i>n || j>m ){
        return 0;
    }
       if(dp[i][j]!=-1){
        return dp[i][j];
       }
        int m1=0,m2=0;
        m1=solve(i+1,j,n,m,dp);
        m2=solve(i,j+1,n,m,dp);
        return dp[i][j]=m1+m2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,n-1,m-1,dp);
    }
};
//TABULATION
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base case: The bottom-right cell has exactly 1 way (destination)
        dp[m - 1][n - 1] = 1;

        // Fill DP table from bottom-right to top-left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    continue; // Skip the last cell (already set to 1)
                }

                int down = 0, right = 0;
                if (i + 1 < m) {
                    down = dp[i + 1][j];
                }
                if (j + 1 < n) {
                    right = dp[i][j + 1];
                }

                dp[i][j] = down + right;
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<dp[i][j]<<" ";
            }cout<<endl;
        }
        return dp[0][0]; // Number of unique paths from (0,0) to (n-1,m-1)
    }
};
