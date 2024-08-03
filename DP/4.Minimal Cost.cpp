//https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

class Solution {
public:
    int solve(int idx, vector<int>& arr, int k, vector<int>& dp) {
       
       //MEMOIZATION
        if (idx == arr.size() - 1) {
            return 0;
        }

    
        if (dp[idx] != -1) {
            return dp[idx];
        }

        int take = INT_MAX;

        for (int i = 1; i <= k; i++) {
            if (idx + i < arr.size()) {
                int cost = abs(arr[idx] - arr[idx + i])
                + solve(idx + i, arr, k, dp);
                take = min(take, cost);
            }
        }

       
        dp[idx] = take;
        return take;
    }

    int minimizeCost(vector<int>& arr, int k) {
        //vector<int> dp(arr.size(), -1); 
        //return solve(0, arr, k, dp);

        //TABULATION
        int n=arr.size();
        vector<int> dp(arr.size(), 0); 
        
        for(int i=n-2; i>=0; i--){
            int mini=INT_MAX;
            for(int j=1; j<=k; j++){
                if(i+j<n){
                    int cost=abs(arr[i]-arr[i+j])+dp[i+j];
                    mini=min(mini,cost);
                }
            }
            dp[i]=mini;
        }
        return dp[0];
    }
};