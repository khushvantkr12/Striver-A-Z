//https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

//MEMOIZATION
class Solution{

	public:
	int MOD=1e9+7;
	int f(int ind,int target,int arr[],vector<vector<int>>&dp,int n){
	    if(ind==n){
	        if(target==0)return 1;
	        return 0;
	    }
	    if(ind>=n)return 0;
	    if(dp[ind][target]!=-1)return dp[ind][target];
	    int take=0;
	    int not_take=f(ind+1,target,arr,dp,n)%MOD;
	    if(target>=arr[ind]){
	     take=f(ind+1,target-arr[ind],arr,dp,n)%MOD;
	    }
	    return dp[ind][target]=(take+not_take)%MOD;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(0,sum,arr,dp,n)%MOD;
	}	  
};

class Solution {
public:
    int MOD = 1e9 + 7;

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base case: If target is 0, there is 1 way (empty subset)
        for (int i = n; i >=0; i--) {
            dp[i][0] = 1;
        }

        // Fill DP table from bottom to top
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int t = 0; t <= target; t++) {
                int not_take = dp[ind + 1][t] % MOD;
                int take = 0;
                if (t >= arr[ind]) {
                    take = dp[ind + 1][t - arr[ind]] % MOD;
                }
                dp[ind][t] = (take + not_take) % MOD;
            }
        }

        return dp[0][target];
    }
};
