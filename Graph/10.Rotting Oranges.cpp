//https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mini = 0;
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time = q.front().second;
            q.pop();

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, -1, 0, 1};

            for (int i = 0; i < 4; i++) {
                int di = x + dx[i];
                int dj = y + dy[i];

                if (di >= 0 && dj >= 0 && di < n && dj < m && grid[di][dj] == 1) {
                    grid[di][dj] = -1000; // Mark as rotten
                    q.push({{di, dj}, time + 1});
                }
            }
            mini = time;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1; // There are still fresh oranges
                }
            }
        }

        return mini;
    }
};
