https://leetcode.com/problems/longest-common-subsequence/submissions/1316265255/

class Solution {
public:
    int solve(int idx1, int idx2, string text1, string text2,vector<vector<int>>&dp) {
        //MEMOIZATION
        if (idx1 >= text1.size() || idx2 >= text2.size()) {
            return 0;
        }

        if(dp[idx1][idx2]!=-1){
         return dp[idx1][idx2];
        }
        if (text1[idx1] == text2[idx2]) {
            return 1 + solve(idx1 + 1, idx2 + 1, text1, text2,dp);
        } else {
            
            int skip1 = solve(idx1 + 1, idx2, text1, text2,dp);
            int skip2 = solve(idx1, idx2 + 1, text1, text2,dp);
             return dp[idx1][idx2]=max(skip1, skip2);
        }

    }

   int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

 //TABULATION
    for (int i = n; i >=0; i--) {
        dp[i][m] = 0;
    }
    for (int j = m; j >=0; j--) {
        dp[n][j] = 0;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (text1[i] == text2[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            } else {
                int skip1=dp[i + 1][j];
                int skip2=dp[i][j+1];
                dp[i][j] = max(skip1, skip2);
            }
        }
    }
   for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            //suppose dp[4][2] is same (e and e) then it takes value from 1 + dp[i + 1][j + 1]..but if not(d!=e) then it takes from dp[i][j] = max(skip1, skip2);
         cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    return dp[0][0];


    }
};
