//https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

//MEMOIZATION
class Solution {
public:
    bool solve(int idx, int sum1, vector<int>& arr, int sum, vector<vector<int>>& dp) {
        // base case
        if (sum1 == sum) {
            return true;
        }
        if (idx >= arr.size() || sum1 > sum) {
            return false;
        }

        if (dp[idx][sum1] != -1) {
            return dp[idx][sum1];
        }

        // option to skip the current element
        int take=0,skip=0;
        skip = solve(idx + 1, sum1, arr, sum, dp);

        if(sum1<sum){
         take = solve(idx + 1, sum1 + arr[idx], arr, sum, dp);
        }
        return dp[idx][sum1] = (skip + take);
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(0, 0, arr, sum, dp);
    }


//TABULATION
bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        //vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
        //return solve(0,arr,target,dp);
        
        for (int i = 0; i <= n; i++) {
          dp[i][0] = true;//dekho sochna aise hai ki agar sum=0 hua to index kya kya hoskta hai..
        }
    
    // Fill the dp table
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= target; j++) {
            bool skip = dp[i + 1][j];
            bool take=false;
            if(j-arr[i]>=0){
                take=dp[i+1][j-arr[i]];
            }
            dp[i][j] = take || skip;
        }
    }
    
    return dp[0][target];
    }     
};