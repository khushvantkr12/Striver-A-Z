class Solution {
public:
    int solve(int idx,bool buy,vector<int>& prices, vector<vector<int>>&dp,int fee){
        //base
       if(idx>=prices.size()){
        return 0;
       }
   if(dp[idx][buy]!=-1){
    return dp[idx][buy];
   }
   

        int take=0,skip=0;
        if(buy){
           
            take=-prices[idx]+solve(idx+1,0,prices,dp,fee);
            skip=solve(idx+1,1,prices,dp,fee);
            return dp[idx][buy]=max(take,skip);
        }else{   
            take=-fee+prices[idx]+solve(idx+1,1,prices,dp,fee);
            skip=solve(idx+1,0,prices,dp,fee);
            return dp[idx][buy]=max(take,skip);
        }
    }
    int maxProfit(vector<int>& prices,int fee) {
         int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return solve(0,1,prices,dp,fee);
        vector<vector<int>>dp(n+1,vector<int>(2,0));

         for (int i = n-1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
               
                if (buy) {
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    dp[i][buy] = max(-fee+prices[i] + dp[i + 1][1], dp[i + 1][0]);
                }
            }
        }
         
        return dp[0][1];
    }
};