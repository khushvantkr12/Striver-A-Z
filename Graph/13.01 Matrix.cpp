//https://leetcode.com/problems/01-matrix/description/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;  

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i,j},0});
                    visited[i][j] = true;
                } 
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist=q.front().second;
            q.pop();
            mat[x][y]=dist;
            for (int i = 0; i < 4; i++) {
                int newdx = x + dx[i];
                int newdy = y + dy[i];
                
                if (newdx >= 0 && newdx < n && newdy >= 0 && newdy < m && visited[newdx][newdy]==false) {
                    q.push({{newdx, newdy},dist+abs(newdx-x)+abs(newdy-y)});
                    visited[newdx][newdy]=true;
                }
                
            }
            
        }

        return mat; 
    }
};