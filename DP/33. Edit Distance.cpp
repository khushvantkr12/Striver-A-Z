//https://leetcode.com/problems/edit-distance/description/

class Solution {
public:
   int solve(int idx1,int idx2,string& word1, string& word2,vector<vector<int>>&dp){
    //base
    //MEMOIZATION
    if(idx2==word2.size()){
        return word1.size()-idx1;
    }
     if(idx1==word1.size()){
        return word2.size()-idx2;
    }
    if(dp[idx1][idx2]!=-1){
        return dp[idx1][idx2];
    }

    int insert=0,replace=0,del=0,skip=0;
    if(word1[idx1]==word2[idx2]){
        skip=solve(idx1+1,idx2+1,word1,word2,dp);
        return dp[idx1][idx2]=skip;
    }else{
        insert=1+solve(idx1,idx2+1,word1,word2,dp);
        replace=1+solve(idx1+1,idx2+1,word1,word2,dp);
        del=1+solve(idx1+1,idx2,word1,word2,dp);
        return dp[idx1][idx2]=min({insert,replace,del});
    }
   }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //return solve(0,0,word1,word2,dp);

        //base
        //TABULATION
        for(int i=0; i<=n; i++){
            dp[i][m]=n-i-1;
        }
         for(int i=0; i<=m; i++){
            dp[n][i]=m-i-1;
        }
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(word1[i]==word2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }else{
                    int del=1+dp[i+1][j];
                    int replace=1+dp[i+1][j+1];
                    int insert=1+dp[i][j+1];
                    dp[i][j]=min({del,replace,insert});
                }
            }
        }
        return 1+dp[0][0];
    }
};