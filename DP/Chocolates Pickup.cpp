//https://www.geeksforgeeks.org/problems/chocolates-pickup/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=chocolates-pickup

class Solution {
public:
int N, M;
vector<vector<vector<int>>> dp;


int solve(int row1, int r1Col, int r2Col, vector<vector<int>>& grid) {
    if (r1Col < 0 || r2Col < 0 || r1Col >= M || r2Col >= M || row1>=N)
        return 0;
    // if (row1 >= N )
    //     return 0;

    if (dp[row1][r1Col][r2Col] != -1)
        return dp[row1][r1Col][r2Col];
        
     if (r1Col == r2Col) {
        return grid[row1][r1Col];
    } 
    
    // Calculate all possible moves
    int m1 = grid[row1][r1Col] + grid[row1][r2Col]+solve(row1 + 1, r1Col - 1, r2Col - 1, grid);
    int m2 = grid[row1][r1Col] + grid[row1][r2Col]+solve(row1 + 1, r1Col - 1, r2Col, grid);
    int m3 = grid[row1][r1Col] + grid[row1][r2Col]+solve(row1 + 1, r1Col - 1, r2Col + 1, grid);
    int m4 = grid[row1][r1Col] + grid[row1][r2Col]+solve(row1 + 1, r1Col,     r2Col - 1, grid);
    int m5 = grid[row1][r1Col] + grid[row1][r2Col]+solve(row1 + 1, r1Col,     r2Col, grid);
    int m6 = grid[row1][r1Col] + grid[row1][r2Col]+solve(row1 + 1, r1Col,     r2Col + 1, grid);
    int m7 = grid[row1][r1Col] + grid[row1][r2Col]+solve(row1 + 1, r1Col + 1, r2Col - 1, grid);
    int m8 = grid[row1][r1Col] + grid[row1][r2Col]+solve(row1 + 1, r1Col + 1, r2Col, grid);
    int m9 = grid[row1][r1Col] + grid[row1][r2Col]+solve(row1 + 1, r1Col + 1, r2Col + 1, grid);

    return dp[row1][r1Col][r2Col]= max({m1, m2, m3, m4, m5, m6, m7, m8, m9});
    
   
}

int solve(int n, int m, vector<vector<int>>& grid) {
    N = n;
    M = m;
    dp = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(M, -1)));
    return solve(0, 0, M - 1, grid);
}
};
