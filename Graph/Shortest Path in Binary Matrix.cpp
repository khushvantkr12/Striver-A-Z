//https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({1, {0, 0}});
        int result=INT_MAX;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        int d1[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int d2[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!pq.empty()) {
            int wt = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == n-1 && y == n-1) {
                return wt;
            }

            for (int i = 0; i < 8; i++) {
                int x1 = x + d1[i];
                int y1 = y + d2[i];

                if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && grid[x1][y1] == 0 && !visited[x1][y1]) {
                    visited[x1][y1] = true;
                    pq.push({wt + 1, {x1, y1}});
                   
                }
                 
            }
        }
        
        return -1;
    }
};