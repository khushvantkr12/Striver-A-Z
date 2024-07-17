//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

class Solution {
public:
    void dfs(vector<vector<int>>& stones, int i, vector<bool>& visited) {
        visited[i] = true;
        
        for (int j = 0; j < stones.size(); ++j) {
            if (!visited[j]&&(stones[j][0] == stones[i][0] || stones[j][1] == stones[i][1])) {
                dfs(stones, j, visited);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++count;
                dfs(stones, i, visited);
                
            }
        }
        
        return n - count;
    }
};
