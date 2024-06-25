//https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

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