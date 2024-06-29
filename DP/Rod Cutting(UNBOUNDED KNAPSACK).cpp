//https://www.geeksforgeeks.org/problems/rod-cutting0840/1
//UNBOUNDED KNAPSACK-->you can take one position value as many as
class Solution {
public:
    int solve(int idx, int price[], int n, vector<vector<int>>& dp) {
        // base case
        if (n == 0) {
            return 0;
        }

        if (idx >= n) {
            return 0;
        }

        if (dp[idx][n] != -1) {
            return dp[idx][n];
        }

        // Skip the current piece
        int skip = solve(idx + 1, price, n, dp);

        // Take the current piece, if possible
        int take = 0;
        int rodlength = idx + 1;
        if (rodlength <= n) {
            take = price[idx] + solve(idx, price, n - rodlength, dp);
        }

        // Store and return the maximum of take and skip
        return dp[idx][n] = max(take, skip);
    }

    int cutRod(int price[], int n) {
        // Create a dp array and initialize with -1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, price, n, dp);
    }
};