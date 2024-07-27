//https://leetcode.com/problems/burst-balloons/description/

class Solution {
public:
    int solve(int i,int j,vector<int>& nums, vector<vector<int>>&dp){
        //base
       if(i>j){
        return 0;
       }
       if(dp[i][j]!=-1){
        return dp[i][j];
       }
        int maxi=INT_MIN;
        for(int k=i; k<=j; k++){
            int steps=0;
             steps=nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
            maxi=max(maxi,steps);
        }
        return dp[i][j]=maxi;
    } 
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
         nums.insert(nums.begin(), 1);//add 1 in begining...
         nums.push_back(1);//add 1 in last
        //APPROACH IS WE HAVE TO MOVE IN OPPOSITE FASHION

        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solve(1,n,nums,dp);

         vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Fill the DP table
        for (int i = n; i >= 1; --i) { 
            for (int j = i; j <= n; ++j) { 
                for (int k = i; k <= j; ++k) { 
                    dp[i][j] = max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
                }
            }
        }

        return dp[1][n];
    }
};
