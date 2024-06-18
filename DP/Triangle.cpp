//https://leetcode.com/problems/triangle/description/
class Solution {
public:
    vector<vector<int>> memo;
    
    int solve(int i, int j, vector<vector<int>>& triangle) {
        if(i>=triangle.size()){
            return 0;
        }
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int m1 = triangle[i][j] + solve(i+1 , j, triangle);
        int m2 = triangle[i][j] + solve(i + 1, j + 1, triangle);
        
        memo[i][j] = min(m1, m2);
        return memo[i][j];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memo.resize(n, vector<int>(n, -1));
        return solve(0, 0, triangle);
    }
};

//DRY RUN

Let's dry run the provided triangle = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]] test case with the given code to understand the flow of execution and how the memoization table is updated.

First call: solve(0, 0, triangle)

i = 0, j = 0, triangle[0][0] = 2
Not at the last row, continue recursion:
Call solve(1, 0, triangle)
Call solve(1, 1, triangle)
Second call: solve(1, 0, triangle)

i = 1, j = 0, triangle[1][0] = 3
Not at the last row, continue recursion:
Call solve(2, 0, triangle)
Call solve(2, 1, triangle)
Third call: solve(2, 0, triangle)

i = 2, j = 0, triangle[2][0] = 6
Not at the last row, continue recursion:
Call solve(3, 0, triangle)
Call solve(3, 1, triangle)
Fourth call: solve(3, 0, triangle)

i = 3, j = 0, triangle[3][0] = 4
At the last row, return triangle[3][0] = 4
Fifth call: solve(3, 1, triangle)

i = 3, j = 1, triangle[3][1] = 1
At the last row, return triangle[3][1] = 1
Back to Third call: solve(2, 0, triangle)

Results from fourth and fifth calls: m1 = 6 + 4 = 10, m2 = 6 + 1 = 7
memo[2][0] = min(10, 7) = 7
Return 7
Sixth call: solve(2, 1, triangle)

i = 2, j = 1, triangle[2][1] = 5
Not at the last row, continue recursion:
Call solve(3, 1, triangle)
Call solve(3, 2, triangle)
Seventh call: solve(3, 1, triangle)

i = 3, j = 1, triangle[3][1] = 1
At the last row, return triangle[3][1] = 1
Eighth call: solve(3, 2, triangle)

i = 3, j = 2, triangle[3][2] = 8
At the last row, return triangle[3][2] = 8
Back to Sixth call: solve(2, 1, triangle)

Results from seventh and eighth calls: m1 = 5 + 1 = 6, m2 = 5 + 8 = 13
memo[2][1] = min(6, 13) = 6
Return 6
Back to Second call: solve(1, 0, triangle)

Results from third and sixth calls: m1 = 3 + 7 = 10, m2 = 3 + 6 = 9
memo[1][0] = min(10, 9) = 9
Return 9
Ninth call: solve(1, 1, triangle)

i = 1, j = 1, triangle[1][1] = 4
Not at the last row, continue recursion:
Call solve(2, 1, triangle)
Call solve(2, 2, triangle)
Tenth call: solve(2, 1, triangle)

i = 2, j = 1, triangle[2][1] = 5
Value is already memoized: memo[2][1] = 6
Return 6
Eleventh call: solve(2, 2, triangle)

i = 2, j = 2, triangle[2][2] = 7
Not at the last row, continue recursion:
Call solve(3, 2, triangle)
Call solve(3, 3, triangle)
Twelfth call: solve(3, 2, triangle)

i = 3, j = 2, triangle[3][2] = 8
At the last row, return triangle[3][2] = 8
Thirteenth call: solve(3, 3, triangle)

i = 3, j = 3, triangle[3][3] = 3
At the last row, return triangle[3][3] = 3
Back to Eleventh call: solve(2, 2, triangle)

Results from twelfth and thirteenth calls: m1 = 7 + 8 = 15, m2 = 7 + 3 = 10
memo[2][2] = min(15, 10) = 10
Return 10
Back to Ninth call: solve(1, 1, triangle)

Results from tenth and eleventh calls: m1 = 4 + 6 = 10, m2 = 4 + 10 = 14
memo[1][1] = min(10, 14) = 10
Return 10
Back to First call: solve(0, 0, triangle)

Results from second and ninth calls: m1 = 2 + 9 = 11, m2 = 2 + 10 = 12
memo[0][0] = min(11, 12) = 11
Return 11
Finally, the minimumTotal function returns 11.