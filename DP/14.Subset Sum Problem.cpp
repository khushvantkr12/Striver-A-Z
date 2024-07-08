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
};

//TABULATION
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
       vector<vector<int>>dp(arr.size(),vector<int>(sum+1,0));
       
       //BASE CASE
      for (int ind = n - 1; ind >= 0; --ind)
    {
        dp[ind][0] = true;//dekho sochna aise hai ki agar sum=0 hua to index kya kya hoskta hai..
    }
        //BASE CASE
        dp[n - 1][arr[n - 1]] = true;//same yaha pe agar index agar last pe pahuch gya to kya ho skta hai
    
       //actual code
        for (int ind = n - 2; ind >= 0; --ind)//why n-2 because in upper code we actually runs from n-1..
    {
        for (int tar = 1; tar <= sum; ++tar)
        {

            int take = (tar >= arr[ind]) ? dp[ind + 1][tar - arr[ind]] : false;
            int not_take = dp[ind + 1][tar];
            dp[ind][tar] = take || not_take;
        }
    }
        return dp[0][sum];
    }
};