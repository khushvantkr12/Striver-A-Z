class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V, 0);
        vector<int>ans;// To store the topological order
        
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
          ans.push_back(x);
            
            // Reduce the indegree of adjacent vertices
            for (auto it : adj[x]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
      if(ans.size()==V){
          return 0;
      }
      return 1;
    }
};
