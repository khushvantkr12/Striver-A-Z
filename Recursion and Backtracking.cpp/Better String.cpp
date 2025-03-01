class Solution {
  public:
    int MOD=1e9;
    int solve(string& s){
        //TABULATION
        int n=s.size();
        vector<int>dp(n+1,0);
        //map for repeated char
        map<char,int>mp;
        dp[0]=1;
        
        for(int i=1; i<=n; i++){
            //suppose s="abcd" then distinct is 2^4=16
            dp[i]=2*dp[i-1];
            char c=s[i-1];
            if(mp.find(c)!=mp.end()){
                dp[i]=dp[i]-dp[mp[c]];
            }
            //push in map to check furthur if it is repeated
            mp[c]=i-1;
        }
        return dp[n]%MOD;
    }
    string betterString(string str1, string str2) {
        // code here
        int sub1 = solve(str1);
        int sub2 = solve(str2);
        
        if(sub2 > sub1) return str2;
        return str1;
    }
};