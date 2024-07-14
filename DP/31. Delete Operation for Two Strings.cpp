//https://leetcode.com/problems/delete-operation-for-two-strings/description/

class Solution {
public:
    int solve(int idx1,int idx2,string& word1, string& word2,int n,int m,vector<vector<int>>&dp){
        //base
    //MEMOIZATION
      if (idx1 == n) return m - idx2; 
        if (idx2 == m) return n - idx1; 
        
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        int take=0,skip1=0,skip2=0;
        if(word1[idx1]==word2[idx2]&&idx1<word1.size()&&idx2<word2.size()){
            take=solve(idx1+1,idx2+1,word1,word2,n,m,dp);
            return dp[idx1][idx2]=take;
        }else{
            skip1=1+solve(idx1+1,idx2,word1,word2,n,m,dp);
            skip2=1+solve(idx1,idx2+1,word1,word2,n,m,dp);
        }
        return dp[idx1][idx2]=min(skip1,skip2);
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        //vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //return solve(0,0,word1,word2,n,m,dp);

        //TABULATION
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // Base cases
        for (int i = 0; i <= n; i++) {
            dp[i][m] = n-i;
        }
        
        for (int j = 0; j <= m; j++) {
            dp[n][j] =m-j;
        }

        // Fill dp array
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int skip1=0,skip2=0;
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    skip1=1+dp[i+1][j];
                    skip2=1+dp[i][j+1];
                     dp[i][j]=min(skip1,skip2);
                }    
            }
        }
        
        return dp[0][0];
    }
};