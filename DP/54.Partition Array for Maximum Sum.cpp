//https://leetcode.com/problems/partition-array-for-maximum-sum/description/

class Solution {
public:
    int solve(int idx,vector<int>& arr, int k,vector<int>&dp){
        //base
        //MEMOIZATION
        int n=arr.size();
       if(idx>=n){
        return 0;
       }
    if(dp[idx]!=-1){
        return dp[idx];
    }

       int maxi=INT_MIN;
       int take=0;
       int maxi1=INT_MIN;
        for(int i=idx; i<min(n,idx+k); i++){
             maxi1=max(maxi1,arr[i]);
            
            take=(i-idx+1)*maxi1+solve(i+1,arr,k,dp);
            maxi=max(maxi,take);
            
        }
        return dp[idx]=maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        //vector<int>dp(n+1,-1);
        //return solve(0,arr,k,dp);
        
        //TABULATION
        vector<int>dp(n+1,0);

        for(int i=n-1; i>=0; i--){
            int maxi=INT_MIN;
            int maxi1=INT_MIN;
             for(int j=i; j<min(n,i+k); j++){
                int take=0;
                maxi1=max(maxi1,arr[j]);
                take=(j-i+1)*maxi1+dp[j+1];
                maxi=max(maxi,take);
             }
             dp[i]=maxi;
        }
        return dp[0];
    }
};