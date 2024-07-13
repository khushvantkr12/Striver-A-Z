//https://leetcode.com/problems/longest-palindromic-subsequence/description/

class Solution {
public:
//MEMOIZATION
    int solve(int idx,int last,string& s, vector<vector<int>>&dp){
        //base

       if(idx==last){
        return 1;
       }
     if(idx>last){
        return 0;
     }


 if(dp[idx][last]!=-1){
        return dp[idx][last];
      }

        int take=0,skip=0,skip2=0;
        if(s[idx]==s[last]){
            take=2+solve(idx+1,last-1,s,dp);
            return dp[idx][last]=take;
        }else{
           skip=solve(idx+1,last,s,dp);
           skip2=solve(idx,last-1,s,dp);
            return dp[idx][last]=max(skip,skip2);
        }  
    }
   int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
   
   //TABULATION
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
   
    // Fill the dp table
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[0][n - 1];


    }
};