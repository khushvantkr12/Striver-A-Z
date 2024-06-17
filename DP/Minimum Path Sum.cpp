//https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        
        if(i >= grid.size() || j >= grid[0].size()) {
            return 1e9;
        }
        if(i == grid.size()-1 && j == grid[0].size()-1) {
            return grid[i][j];
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int m1 = grid[i][j] + solve(i + 1, j, grid, dp);
        int m2 = grid[i][j] + solve(i, j + 1, grid, dp);

        return dp[i][j] = min(m1, m2);
    }

    int minPathSum(vector<vector<int>>& grid) {
     
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, grid, dp);
    }
};

//DRY RUN

Let's perform a dry run of the given grid = [[1, 3, 1], [1, 5, 1], [4, 2, 1]] with the minPathSum function. Here's the process step-by-step:

Initialization:
m = 3 (number of rows)
n = 3 (number of columns)
dp = [[-1, -1, -1], [-1, -1, -1], [-1, -1, -1]] (initial DP table)
Execution:
Step 1: Call solve(0, 0, grid, dp)
Current cell (0, 0) with value 1
This is not the last cell, so continue
Step 2: Recursive calls from (0, 0)
Call solve(1, 0, grid, dp) to explore the path going down
Call solve(0, 1, grid, dp) to explore the path going right
Step 3: Call solve(1, 0, grid, dp)
Current cell (1, 0) with value 1
This is not the last cell, so continue
Step 4: Recursive calls from (1, 0)
Call solve(2, 0, grid, dp) to explore the path going down
Call solve(1, 1, grid, dp) to explore the path going right
Step 5: Call solve(2, 0, grid, dp)
Current cell (2, 0) with value 4
This is not the last cell, so continue
Step 6: Recursive calls from (2, 0)
Call solve(3, 0, grid, dp) (out of bounds, returns 1e9)
Call solve(2, 1, grid, dp)
Step 7: Call solve(2, 1, grid, dp)
Current cell (2, 1) with value 2
This is not the last cell, so continue
Step 8: Recursive calls from (2, 1)
Call solve(3, 1, grid, dp) (out of bounds, returns 1e9)
Call solve(2, 2, grid, dp)
Step 9: Call solve(2, 2, grid, dp)
Current cell (2, 2) with value 1
This is the last cell, return 1
Step 10: Return to solve(2, 1, grid, dp)
Minimum path sum from (2, 1) is 2 (current cell) + 1 (next cell) = 3
Update dp[2][1] = 3
Return 3
Step 11: Return to solve(2, 0, grid, dp)
Minimum path sum from (2, 0) is 4 (current cell) + 3 (next cell) = 7
Update dp[2][0] = 7
Return 7
Step 12: Return to solve(1, 0, grid, dp)
Minimum path sum from (1, 0) by going down is 1 (current cell) + 7 (next cell) = 8
Continue exploring right path by calling solve(1, 1, grid, dp)
Step 13: Call solve(1, 1, grid, dp)
Current cell (1, 1) with value 5
This is not the last cell, so continue
Step 14: Recursive calls from (1, 1)
Call solve(2, 1, grid, dp) (already computed, returns 3)
Call solve(1, 2, grid, dp)
Step 15: Call solve(1, 2, grid, dp)
Current cell (1, 2) with value 1
This is not the last cell, so continue
Step 16: Recursive calls from (1, 2)
Call solve(2, 2, grid, dp) (already computed, returns 1)
Call solve(1, 3, grid, dp) (out of bounds, returns 1e9)
Step 17: Return to solve(1, 2, grid, dp)
Minimum path sum from (1, 2) is 1 (current cell) + 1 (next cell) = 2
Update dp[1][2] = 2
Return 2
Step 18: Return to solve(1, 1, grid, dp)
Minimum path sum from (1, 1) by going right is 5 (current cell) + 2 (next cell) = 7
Update dp[1][1] = 7
Return 7
Step 19: Return to solve(1, 0, grid, dp)
Minimum path sum from (1, 0) by going right is 1 (current cell) + 7 (next cell) = 8
Both down and right paths result in the same sum, 8
Update dp[1][0] = 8
Return 8
Step 20: Return to solve(0, 0, grid, dp)
Minimum path sum from (0, 0) by going down is 1 (current cell) + 8 (next cell) = 9
Continue exploring right path by calling solve(0, 1, grid, dp)
Step 21: Call solve(0, 1, grid, dp)
Current cell (0, 1) with value 3
This is not the last cell, so continue
Step 22: Recursive calls from (0, 1)
Call solve(1, 1, grid, dp) (already computed, returns 7)
Call solve(0, 2, grid, dp)
Step 23: Call solve(0, 2, grid, dp)
Current cell (0, 2) with value 1
This is not the last cell, so continue
Step 24: Recursive calls from (0, 2)
Call solve(1, 2, grid, dp) (already computed, returns 2)
Call solve(0, 3, grid, dp) (out of bounds, returns 1e9)
Step 25: Return to solve(0, 2, grid, dp)
Minimum path sum from (0, 2) is 1 (current cell) + 2 (next cell) = 3
Update dp[0][2] = 3
Return 3
Step 26: Return to solve(0, 1, grid, dp)
Minimum path sum from (0, 1) by going right is 3 (current cell) + 3 (next cell) = 6
Update dp[0][1] = 6
Return 6
Step 27: Return to solve(0, 0, grid, dp)
Minimum path sum from (0, 0) by going right is 1 (current cell) + 6 (next cell) = 7
The final result is the minimum of the two paths:
Down: 9
Right: 7
Update dp[0][0] = 7
Return 7
Result:
The minimum path sum is 7. The path is 1 -> 3 -> 1 -> 1 -> 1.