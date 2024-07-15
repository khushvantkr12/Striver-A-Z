//https://leetcode.com/problems/shortest-common-supersequence/description/

class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
         int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
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
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<=m; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        string ans;
        int i=0,j=0;
        while(i<n && j<m){
            if(text1[i]==text2[j]){
                ans+=text1[i];
                i++;
                j++;
               
            }
           else if(dp[i][j+1]>=dp[i+1][j]){
                 ans+=text2[j];
                 j++;
            }
            else{
                ans+=text1[i];
                i++;
            }
        }
        while(i<n){
            ans+=text1[i];
            i++;
        }
        while(j<m){
            ans+=text2[j];
            j++;
        }
        return ans;
    }
};