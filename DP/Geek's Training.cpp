https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training
class Solution {
  public:
    int dp[100001][3];
    //There are 2 choices dependent on the previous choice we have picked, if we picked 0, so we can pick only 1 and 2 in next round, and similarly for other choices as well
    int solve(int index, vector<vector<int>>& points, int choice){
        if(index >= points.size()) return 0;
        
        if(dp[index][choice] != -1) return dp[index][choice];
        if(choice == 0){
            return dp[index][choice] = points[index][choice] +
            max(solve(index + 1, points, 1), solve(index + 1, points, 2));
        }
        else if(choice == 1){
            return dp[index][choice] = points[index][choice] +
            max(solve(index + 1, points, 0), solve(index + 1, points, 2));
        }
        else if(choice == 2){
            return dp[index][choice] = points[index][choice] +
            max(solve(index + 1, points, 0), solve(index + 1, points, 1));
        }
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        memset(dp, -1, sizeof(dp));
       int x=solve(0, points, 0);
       int y=solve(0, points, 1);
       int z=solve(0, points, 2);
       return max({x,y,z});
    }
};
//TABULATION
class Solution {
public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(3, 0));

        // Base case: Last row is the same as points[n-1]
        dp[n - 1][0] = points[n - 1][0];
        dp[n - 1][1] = points[n - 1][1];
        dp[n - 1][2] = points[n - 1][2];

        // Fill DP table from back to front
        for (int index = n - 2; index >= 0; index--) {
            dp[index][0] = points[index][0] + max(dp[index + 1][1], dp[index + 1][2]);
            dp[index][1] = points[index][1] + max(dp[index + 1][0], dp[index + 1][2]);
            dp[index][2] = points[index][2] + max(dp[index + 1][0], dp[index + 1][1]);
        }

        // Maximum value among the choices at the first index
        return max(dp[0][0], max(dp[0][1], dp[0][2]));
    }
};


//DRY RUN
Input:
n = 3
points = [[1,2,5],[3,1,1],[3,3,3]]
Output:
11

Step-by-Step Computation
Starting with choice 0 at index 0:

solve(0, points, 0)
Recursive Calls from (0, 0):

solve(1, points, 1)
solve(1, points, 2)
Recursive Calls from (1, 1):

solve(2, points, 0)
solve(2, points, 2)
Recursive Calls from (2, 0):

solve(3, points, 1) (out of bounds, returns 0)
solve(3, points, 2) (out of bounds, returns 0)
Points collected from (2, 0) = points[2][0] = 3
Total points = 3
Recursive Calls from (2, 2):

solve(3, points, 0) (out of bounds, returns 0)
solve(3, points, 1) (out of bounds, returns 0)
Points collected from (2, 2) = points[2][2] = 3
Total points = 3
Return to (1, 1):

Points collected from (1, 1) = points[1][1] + max(3, 3) = 1 + 3 = 4
Recursive Calls from (1, 2):

solve(2, points, 0)
solve(2, points, 1)
Recursive Calls from (2, 0) is already computed as 3.

Recursive Calls from (2, 1):

solve(3, points, 0) (out of bounds, returns 0)
solve(3, points, 2) (out of bounds, returns 0)
Points collected from (2, 1) = points[2][1] = 3
Total points = 3
Return to (1, 2):

Points collected from (1, 2) = points[1][2] + max(3, 3) = 1 + 3 = 4
Return to (0, 0):

Points collected from (0, 0) = points[0][0] + max(4, 4) = 1 + 4 = 5
Similarly, compute for starting choices 1 and 2:
Starting with choice 1 at index 0:

solve(0, points, 1)
Recursive Calls from (0, 1):

solve(1, points, 0)
solve(1, points, 2)
Recursive Calls from (1, 0):

solve(2, points, 1)
solve(2, points, 2)
Recursive Calls from (2, 1) is already computed as 3.

Recursive Calls from (2, 2) is already computed as 3.

Return to (1, 0):

Points collected from (1, 0) = points[1][0] + max(3, 3) = 3 + 3 = 6
Recursive Calls from (1, 2) is already computed as 4.

Return to (0, 1):

Points collected from (0, 1) = points[0][1] + max(6, 4) = 2 + 6 = 8
Starting with choice 2 at index 0:

solve(0, points, 2)
Recursive Calls from (0, 2):

solve(1, points, 0)
solve(1, points, 1)
Recursive Calls from (1, 0) is already computed as 6.

Recursive Calls from (1, 1) is already computed as 4.

Return to (0, 2):

Points collected from (0, 2) = points[0][2] + max(6, 4) = 5 + 6 = 11
Final Calculation:
The final results are:
x = solve(0, points, 0) = 5
y = solve(0, points, 1) = 8
z = solve(0, points, 2) = 11
The maximum points are max({x, y, z}) = 11.
Explanation with Dry Run:
Starting with choice 0, we calculate solve(0, points, 0):

From (0,0), choose 1 or 2 in the next row.
For choice 1 in the next row, maximum points: 1 + max(3, 3) = 4
For choice 2 in the next row, maximum points: 1 + max(3, 3) = 4
Total for choice 0: 1 + max(4, 4) = 5
Starting with choice 1, we calculate solve(0, points, 1):

From (0,1), choose 0 or 2 in the next row.
For choice 0 in the next row, maximum points: 2 + max(3, 3) = 6
For choice 2 in the next row, maximum points: 2 + max(3, 3) = 4
Total for choice 1: 2 + max(6, 4) = 8
Starting with choice 2, we calculate solve(0, points, 2):

From (0,2), choose 0 or 1 in the next row.
For choice 0 in the next row, maximum points: 5 + max(3, 3) = 6
For choice 1 in the next row, maximum points: 5 + max(3, 3) = 4
Total for choice 2: 5 + max(6, 4) = 11
Therefore, the maximum points obtained is 11.

The detailed recursive steps and calculations confirm that the code works correctly to compute the maximum points, considering all possible choices at each step.
