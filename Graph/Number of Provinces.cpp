class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int n) {
        if (visited[node]) {
            return;
        }
        visited[node] = true;
        for (int it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n); // Correct initialization
        for (int i = 0; i < n; i++) { // Corrected loop indices
            for (int j = 0; j < n; j++) { // Corrected loop indices
                if (isConnected[i][j] == 1) { // Avoid self-loops
                    adj[i].push_back(j); // Corrected indexing
                }
            }
        }
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) { // Corrected loop
            if (!visited[i]) { // Corrected access
                count++;
                dfs(i, adj, visited, n);
            }
        }
        return count;
    }
};
