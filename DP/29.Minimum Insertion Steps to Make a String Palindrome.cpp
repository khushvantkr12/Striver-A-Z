//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

class Solution {
public:
    int solve(int idx,int last,string& s, vector<vector<int>>&dp){
        //base
        //MEMOIZATION
       if(idx==last){
        return 0;
       }
     if(idx>last){
        return 0;
     }
     if(dp[idx][last]!=-1){
        return dp[idx][last];
     }


        int take1=0,take2=0,skip=0;
        if(s[idx]==s[last]){
            skip=solve(idx+1,last-1,s,dp);
            return dp[idx][last]=skip;
        }else{
        take1=1+solve(idx+1,last,s,dp);
        take2=1+solve(idx,last-1,s,dp);
        }
        return dp[idx][last]=min(take1,take2);
    }
    int minInsertions(string s) {
        int n=s.size();
        //vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        //return solve(0,n-1,s,dp);
        //here in bottom up i assume n and 0..so it become easy
         vector<vector<int>>dp(n,vector<int>(n,0));
         //TABULATION
         for(int i=n-2;i>=0; i--){
            for(int j=i+1; j<=n-1; j++){
                int skip1=0,skip2=0;
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }else{
                    skip1=1+dp[i+1][j];
                    skip2=1+dp[i][j-1];
                    dp[i][j]=min(skip1,skip2);
                }
                
            }
         }
      return dp[0][n-1];
    }
};