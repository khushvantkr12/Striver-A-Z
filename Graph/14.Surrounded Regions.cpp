//https://leetcode.com/problems/surrounded-regions/description/

class Solution {
public:
    void dfs(int u, int v, vector<vector<char>>& board, vector<vector<bool>>& visited, int n, int m) {
        // Base case
        if (u < 0 || u >= n || v < 0 || v >= m || visited[u][v] || board[u][v] == 'X') {
            return;
        }
        visited[u][v] = true;

        dfs(u + 1, v, board, visited, n, m);
        dfs(u - 1, v, board, visited, n, m);
        dfs(u, v + 1, board, visited, n, m);
        dfs(u, v - 1, board, visited, n, m);
    }

    void solve(vector<vector<char>>& board) {
           //sabse pahle harek corner(top,left,bottom,right) pe jaao aur jaha bhi 'O' dikhe waahan se dfs call lagao 4 direction me..aur sbko visited mark karte jaao...  
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Check the first and last column
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(i, 0, board, visited, n, m);
            }
            if (board[i][m - 1] == 'O' && !visited[i][m - 1]) {
                dfs(i, m - 1, board, visited, n, m);
            }
        }

        // Check the first and last row
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && !visited[0][i]) {
                dfs(0, i, board, visited, n, m);
            }
            if (board[n - 1][i] == 'O' && !visited[n - 1][i]) {
                dfs(n - 1, i, board, visited, n, m);
            }
        }

        // Convert all unvisited 'O's to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && visited[i][j]==false) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};