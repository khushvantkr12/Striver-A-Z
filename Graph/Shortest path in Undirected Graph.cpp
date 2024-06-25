//https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance

// User function Template for C++
class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<bool> visited(N, false);
        vector<vector<int>> adj(N);
        
        // Construct the adjacency list
        for (auto it : edges) {
            int x = it[0];
            int y = it[1];
            // undirected
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        queue<pair<int, int>> q;
        q.push({src, 0});
        //visited[src] = true;

        vector<int> ans(N, INT_MAX);
        ans[src] = 0;

        while (!q.empty()) {
            int x = q.front().first;
            int dist = q.front().second;
            q.pop();

            for (auto u : adj[x]) {
                if (!visited[u]) {
                    q.push({u, dist + 1});
                    visited[u] = true;
                   
                }
                 ans[u] = min(ans[u],dist+1);
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == INT_MAX) {
                ans[i] = -1;
            }
        }

        return ans;
    }
};