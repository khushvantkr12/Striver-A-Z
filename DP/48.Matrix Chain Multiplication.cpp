//https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=matrix-chain-multiplication

class Solution{
public:
    int solve(int i,int j, int arr[],vector<vector<int>>&dp){
        //base
       if(i==j){
           return 0;
       } 
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
       //run a for loop
       int mini=INT_MAX;
       for(int k=i; k<j; k++){
           int steps=arr[i-1]*arr[k]*arr[j]+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
           if(steps<mini){
               mini=steps;
           }
       }
        return dp[i][j]=mini;
        
    }
  int matrixMultiplication(int N, int arr[]) {
       //vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        //return solve(1,N-1,arr,dp);
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i=N-1; i>=1; i--) {
        //here j cant go beyond i because in base case i==j return 0
        for (int  j=i+1; j<N; j++) {
            int mini=1e9;
            for (int k = i; k < j; k++) {
                int cost = arr[i - 1] * arr[k] * arr[j]+dp[i][k] + dp[k + 1][j]; 
                if (cost < mini) {
                    mini=cost;
                }
                dp[i][j]=mini;
            }
        }
    }
    
    return dp[1][N - 1];
}
};