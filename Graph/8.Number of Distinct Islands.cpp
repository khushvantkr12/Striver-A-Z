//https://www.geeksforgeeks.org/problems/number-of-distinct-islands/0
//TC-O(N*M*4)
//SC-O(N*M)
class Solution {
public:
    void dfs(int u, int v, vector<vector<int>>& grid, vector<pair<int, int>>& ans, int start_idx_i, int start_idx_j, int n, int m) {
        if (u < 0 || u >= n || v < 0 || v >= m || grid[u][v] == 0) {
            return;
        }

        grid[u][v] = 0;

       
        ans.push_back({u - start_idx_i, v - start_idx_j});
        
        dfs(u + 1, v, grid, ans, start_idx_i, start_idx_j, n, m);
        dfs(u, v + 1, grid, ans, start_idx_i, start_idx_j, n, m);
        dfs(u - 1, v, grid, ans, start_idx_i, start_idx_j, n, m);
        dfs(u, v - 1, grid, ans, start_idx_i, start_idx_j, n, m);
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
         //striver approach:dekho sbse pahle grid[i][j] jis index ko hit karega usko base index maan lena fir waha se jaha jaha index pe jayega usko base index se minus karwa ke set me daalte jaana..issme duplicate set me nhi aayega aur last me set.size() return karwa dena
        set<vector<pair<int, int>>> s;
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> ans;
                    dfs(i, j, grid, ans, i, j, n, m);
                    s.insert(ans);
                }
            }
        }
        return s.size();
    }
};
