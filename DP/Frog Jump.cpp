
// class Solution {
//   public:
//     int solve(int i, vector<int>& height, vector<int>& dp) {
//         // Base case
//         if (i >= height.size() - 1) {
//             return 0;
//         }

//         if (dp[i] != -1) {
//             return dp[i];
//         }

//         int one = abs(height[i] - height[i + 1]) + solve(i + 1, height, dp);
//         int two = INT_MAX;
        
//         if (i + 2 < height.size()) {
//             two = abs(height[i] - height[i + 2]) + solve(i + 2, height, dp);
//         }

//         return dp[i] = min(one, two);
//     }

//     int minCost(vector<int>& height) {
//         int n = height.size();
//         vector<int> dp(n, -1);
//         return solve(0, height, dp);  // Start from index 0
//     }
// };

class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0; // If there's only one stone, no cost

        vector<int> dp(n, 0);
        dp[n - 1] = 0; // No cost at the last stone
        dp[n - 2] = abs(height[n - 1] - height[n - 2]); // Only one step possible from second-last stone

        for (int i = n - 3; i >= 0; i--) {
            int one = dp[i + 1] + abs(height[i] - height[i + 1]);
            int two = dp[i + 2] + abs(height[i] - height[i + 2]);
            dp[i] = min(one, two);
        }

        return dp[0]; // Minimum cost to reach the last stone from the first stone
    }
};
