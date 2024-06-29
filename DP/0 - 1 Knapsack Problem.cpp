//https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution {
public:
    int solve(int idx, int W, int wt[], int val[], int n, std::vector<std::vector<int>>& dp) {
        // Base cases
        if (idx >= n || W <= 0) {
            return 0;
        }
        
        // Check if the result is already computed
        if (dp[idx][W] != -1) {
            return dp[idx][W];
        }
        
        // Skip the current item
        int skip = solve(idx + 1, W, wt, val, n, dp);
        
        // Take the current item (only if the weight allows)
        int take = 0;
        if (W >= wt[idx]) {
            take = val[idx] + solve(idx + 1, W - wt[idx], wt, val, n, dp);
        }
        
        // Store the result in dp array and return the maximum of take and skip
        return dp[idx][W] = std::max(take, skip);
    }
    
    int knapSack(int W, int wt[], int val[], int n) { 
        // Create a dp array initialized to -1
        std::vector<std::vector<int>> dp(n, std::vector<int>(W + 1, -1));
        return solve(0, W, wt, val, n, dp);
    }
};