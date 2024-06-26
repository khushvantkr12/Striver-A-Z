//https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution{
  public:
  int solve(int idx,int x,int arr[], int n,int sum,vector<vector<int>>&dp){
      //base
      int ans=INT_MAX;
      if(idx==n){
          ans=min(ans,abs(sum-(x-sum)));
          return ans;
      }
      if(idx>n){
          return 0;
      }
      if(dp[idx][sum]!=-1){
          return dp[idx][sum];
      }
      
      
      int take=0,skip=0;
      take=solve(idx+1,x,arr,n,sum+arr[idx],dp);
      skip=solve(idx+1,x,arr,n,sum,dp);
      return dp[idx][sum]=min(take,skip);
  }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    //int x=accumulate(arr[0],arr[n-1],0);
	    int x=0;
	    for(int i=0; i<n; i++){
	        x+=arr[i];
	    }
	    vector<vector<int>>dp(n+1,vector<int>(x,-1));
	    return solve(0,x,arr,n,0,dp);
	} 
};