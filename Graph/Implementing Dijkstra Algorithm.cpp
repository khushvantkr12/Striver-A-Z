//https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Initialize distances with infinity (1e9 in this case)
        vector<int> result(V, 1e9);
        
        // Distance to source vertex is 0
        result[S] = 0;
        
        // Push source vertex into priority queue
        pq.push({0, S});
        
        // Dijkstra's algorithm
        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Traverse all adjacent nodes of the current node
            for (auto u : adj[node]) {
                int curr_node = u[0];
                int curr_wt = u[1];
                
                // If a shorter path to curr_node is found through node
                if (result[node] + curr_wt < result[curr_node]) {
                    result[curr_node] = result[node] + curr_wt;
                    pq.push({result[curr_node], curr_node});
                }
            }
        }
        
        return result;
    
    }
};