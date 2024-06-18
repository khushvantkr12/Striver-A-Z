class Solution {
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        vector<int> result; // To store the topological order
        
        // Calculate the indegree of each vertex
        for (int i = 0; i < V; i++) {
            for (auto u : adj[i]) {
                indegree[u]++;
            }
        }
        
        queue<int> q;
        
        // Push all vertices with indegree 0 into the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Process vertices in the queue
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            result.push_back(x); // Add to the result
            
            // Reduce the indegree of adjacent vertices
            for (auto it : adj[x]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);//hm tabhi queue me daalenge jb indegree 0 hoga
                }
            }
        }
        
        return result;
    }
};