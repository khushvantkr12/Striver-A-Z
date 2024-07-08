//https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items

class Solution {
public:
//MEMOIZATION
    int solve(int i, int N, int W, int val[], int wt[], vector<vector<int>>& dp) {
        // Base case
        if (i == N-1) {
            return (W/wt[N-1])*val[N-1];
        }

        
        if (dp[i][W] != -1) {
            return dp[i][W];
        }

        int take = 0, skip = 0;
        if (W >= wt[i]) {
            take = val[i] + solve(i, N, W - wt[i], val, wt, dp);
        }
        skip = solve(i + 1, N, W, val, wt, dp);

        // Store the result and return it
        return dp[i][W] = max(take, skip);
    }

    int knapSack(int N, int W, int val[], int wt[]) {
        // Initialize a dp array for memoization
        vector<vector<int>> dp(N+1, vector<int>(W + 1, -1));
        //return solve(0, N, W, val, wt, dp);
        
        //TABULATION
       for(int w=0; w<=W; w++){
           dp[N-1][w]=(W/wt[N-1])*val[N-1];
       }
        
        for(int i=N-1; i>=0; i--){
            for(int w=0; w<=W; w++){
                int take=0,skip=0;
                if(w>=wt[i]){
                    take=val[i]+dp[i][w-wt[i]];
                }
                skip=dp[i+1][w];
                dp[i][w]=max(take,skip);
            }
        }
        return dp[0][W];
    }
};
