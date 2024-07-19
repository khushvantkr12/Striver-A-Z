class Solution {
public:
    int solve(int idx,bool buy,vector<int>& prices, vector<vector<vector<int>>>&dp,int k){
        //base
       if(idx>=prices.size()){
        return 0;
       }
   if(dp[idx][k][buy]!=-1){
    return dp[idx][k][buy];
   }
   if(k==0){
    return 0;
   }

        int take=0,skip=0;
        if(buy){
           
            take=-prices[idx]+solve(idx+1,0,prices,dp,k);
            skip=solve(idx+1,1,prices,dp,k);
            return dp[idx][k][buy]=max(take,skip);
        }else{   
            take=prices[idx]+solve(idx+1,1,prices,dp,k-1);
            skip=solve(idx+1,0,prices,dp,k);
            return dp[idx][k][buy]=max(take,skip);
        }
    }
    int maxProfit(int k,vector<int>& prices) {
         int n=prices.size();
        //vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(101,vector<int>(2,-1)));
        //return solve(0,1,prices,dp,k);
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,0)));

         for (int i = n-1; i >= 0; i--) {
             for(int j=1; j<=k; j++){
            for (int buy = 0; buy < 2; buy++) {
               
                if (buy) {
                    dp[i][j][buy] = max(-prices[i] + dp[i + 1][j][0], dp[i + 1][j][1]);
                } else {
                    dp[i][j][buy] = max(prices[i] + dp[i + 1][j-1][1], dp[i + 1][j][0]);
                }
            }
        }
         }
        return dp[0][k][1];
    }
};