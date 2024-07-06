// https://leetcode.com/problems/coin-change/description/

class Solution {
public:
   
    int solve(int idx, vector<int>& coins, int amount,vector<vector<int>>&dp) {
        // base cases
        if (amount == 0) {
            return 0;
        }
        if (idx >= coins.size() ) {
            return 1e9;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        // take the current coin
        int take=1e9,skip=0;
        if (amount - coins[idx] >= 0) {
           take=1+solve(idx, coins, amount - coins[idx],dp);
        }
        // skip the current coin
       skip= solve(idx + 1, coins, amount,dp);
       return dp[idx][amount]=min(take,skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int mini=solve(0, coins, amount,dp);
        return (mini == 1e9) ? -1 : mini;
    }
};
