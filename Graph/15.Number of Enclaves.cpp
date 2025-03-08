//https://leetcode.com/problems/number-of-enclaves/description/

class Solution {
public:
    void dfs(int u, int v, vector<vector<int>>& grid, vector<vector<bool>>& visited, int n, int m) {
        // base case
        if (u < 0 || u >= n || v < 0 || v >= m || grid[u][v] == 0 || visited[u][v] == true) {
            return;
        }
        visited[u][v] = true;
        dfs(u + 1, v, grid, visited, n, m);
        dfs(u, v + 1, grid, visited, n, m);
        dfs(u - 1, v, grid, visited, n, m);
        dfs(u, v - 1, grid, visited, n, m);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Traverse the boundary rows
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && visited[i][0] == false) {
                dfs(i, 0, grid, visited, n, m);
            }
            if (grid[i][m-1] == 1 && visited[i][m-1] == false) {
                dfs(i, m-1, grid, visited, n, m);
            }
        }

        // Traverse the boundary columns
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && visited[0][i] == false) {
                dfs(0, i, grid, visited, n, m);
            }
            if (grid[n-1][i] == 1 && visited[n-1][i] == false) {
                dfs(n-1, i, grid, visited, n, m);
            }
        }

        // Count the number of enclaves (cells that are land and not visited)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    count++;
                }
            }
        }
        return count;
    }
};

//BFS
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
           int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !vis[newX][newY] && grid[newX][newY] == 1) {
                    q.push({newX, newY});
                    vis[newX][newY] = 1;
                }
            }
        }
        int count=0;
       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                   count++;  
                }
            }
        }
        return count;
    }
};