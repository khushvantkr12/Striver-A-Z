//https://leetcode.com/problems/coin-change-ii/description/

class Solution {
public:
 int solve(int idx, vector<int>& coins, int amount,vector<vector<int>>&dp) {
        // base cases
        if(idx==coins.size()){
        if (amount == 0) {
            return 1;
        }
        return 0;
        }
        if (idx > coins.size() ) {
            return 0;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        // take the current coin
        int take=0,skip=0;
        if (amount - coins[idx] >= 0) {
           take=solve(idx, coins, amount - coins[idx],dp);
        }
        // skip the current coin
       skip= solve(idx + 1, coins, amount,dp);
       return dp[idx][amount]=take+skip;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(0,coins,amount,dp);
    }
};