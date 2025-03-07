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

//tabulation

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e9));

        // Base case: If amount is 0, we need 0 coins
        for (int i = n; i >=0; i--) {
            dp[i][0] = 0;
        }

        // Fill DP table from bottom to top
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int amt = 0; amt <= amount; amt++) {
                int skip = dp[idx + 1][amt];  // Skip the current coin
                int take = 1e9;
                if (amt >= coins[idx]) {
                    take = 1 + dp[idx][amt - coins[idx]];  // Take the current coin
                }
                dp[idx][amt] = min(take, skip);
            }
        }

        return (dp[0][amount] == 1e9) ? -1 : dp[0][amount];
    }
};
