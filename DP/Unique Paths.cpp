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