//https://leetcode.com/problems/distinct-subsequences/description/

class Solution {
public:
int MOD=1e9+7;
    int solve(int idx1, int idx2, string& s, string& t, vector<vector<int>>& dp) {
        // Base cases
        if (idx2 == t.size()) return 1; 
        if (idx1 == s.size()) return 0;  

        if (dp[idx1][idx2] != -1) return dp[idx1][idx2]; 

    
        int take1 = 0,take2=0, skip = 0;
        if (s[idx1] == t[idx2]) {
            take1 = solve(idx1 + 1, idx2 + 1, s, t, dp);  
            take2 = solve(idx1 + 1, idx2, s, t, dp);
            return dp[idx1][idx2] = take1+take2;  
        }else{
        return dp[idx1][idx2] = solve(idx1 + 1, idx2, s, t, dp);  
        // return skip;
        }
       
    }

    int numDistinct(string s, string t) {
         long long n = s.size();
         long long m = t.size();
        //vector<vector<int>> dp(n, vector<int>(m, -1));  
        //return solve(0, 0, s, t, dp);

        //always try to take n+1,m+1..sometime it gets runtime error
         vector<vector<long>> dp(n+1, vector<long>(m+1, 0));

        for(int i=0; i<=n; i++){
            dp[i][m]=1;
        }  
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(s[i]==t[j]){
                  dp[i][j]=(dp[i+1][j+1]+dp[i+1][j])%MOD;
                }else{
                dp[i][j]=dp[i+1][j];
                }
                
            }
        }
    //     for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //      cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
        return dp[0][0]%MOD;
    }
};