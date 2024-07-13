//https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution{
    public:

//MEMOIZATION
int solve(int ind1, int ind2, string s1, string s2, vector<vector<int>>&dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        //match
        if(s1[ind1] == s2[ind2]){
            dp[ind1][ind2] = 1 + solve(ind1-1, ind2-1, s1, s2, dp);
        }
        else 
            dp[ind1][ind2] = 0;
            
        return dp[ind1][ind2];
    }
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                solve(i, j, s1, s2, dp);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;

        //TABULATION
        int ans=0;
         for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return ans;
    }
};