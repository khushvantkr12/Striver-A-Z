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
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
        return solve(0,1,prices,dp,2);
    }
};