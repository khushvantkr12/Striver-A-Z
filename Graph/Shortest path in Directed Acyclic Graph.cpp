//https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph

//REMEMBER USE "1e9" instead of "INT_MAX" because it cause integer overflow
class Solution {
public:
    void dfs(int i, vector<bool>& visited, vector<vector<pair<int, int>>>& adj, stack<int>& st) {
        visited[i] = true;
        for (auto it : adj[i]) {
            if (!visited[it.first]) {
                dfs(it.first, visited, adj, st);
            }
        }
        st.push(i);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(N);
        vector<bool> visited(N, false);
        for (auto it : edges) {
            int x = it[0];
            int y = it[1];
            int z = it[2];
            adj[x].push_back({y, z});
        }

        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }

        vector<int> result(N,1e9);
        result[0] = 0; // Assuming 0 is the starting node

        while (!st.empty()) {
            int node = st.top();
            st.pop();
           
                for (auto it : adj[node]) {
                    int next_node = it.first;
                    int weight = it.second;
                    if (result[node] + weight < result[next_node]) {
                        result[next_node] = result[node] + weight;
                    }
               
            }
        }

        for (int i = 0; i < result.size(); i++) {
            if (result[i] == 1e9) {
                result[i] = -1;
            }
        }

        return result;
    }
};