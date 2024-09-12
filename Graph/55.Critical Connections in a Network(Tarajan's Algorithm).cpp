//https://leetcode.com/problems/critical-connections-in-a-network/description/

class Solution {
public:
    void dfs(int node, int parent, int timer, vector<int>& visited, vector<vector<int>>& ans, vector<int>& disc, vector<int>& low, vector<vector<int>>& adj) {
        visited[node] = 1;
        low[node] = disc[node] = timer;
        timer++;

        for(auto it : adj[node]) {
            if(it == parent) {
                continue;
            }
            if(!visited[it]) {
                dfs(it, node, timer, visited, ans, disc, low, adj);
                low[node] = min(low[node], low[it]);
                // check if the edge is a bridge
                if(low[it] > disc[node]) {
                    ans.push_back({it, node});
                }
            } else {
                // back edge
                low[node] = min(low[node], disc[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
// disc (Discovery Time):
// Purpose: The disc array records the time (or order) when a node is first visited during the Depth First Search (DFS) traversal.
// Function: It helps in keeping track of the discovery time of each node. For each node u, disc[u] is set to the current time when the DFS reaches node u.
// low (Lowest Discovery Time Reachable):
// Purpose: The low array stores the lowest discovery time reachable from a node u, either by its own subtree or through a back edge.
        vector<int> visited(n, 0);
        vector<int> disc(n, INT_MAX);
        vector<int> low(n, INT_MAX);
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, -1, 0, visited, ans, disc, low, adj);
            }
        }

        return ans;
    }
};

//DRY RUN

Let's walk through a dry run of your algorithm with n = 4 and connections = [[0,1],[1,2],[2,0],[1,3]].

Initial Setup:
adj (Adjacency list):
0: [1, 2]
1: [0, 2, 3]
2: [1, 0]
3: [1]
visited = [0, 0, 0, 0]
disc = [INT_MAX, INT_MAX, INT_MAX, INT_MAX]
low = [INT_MAX, INT_MAX, INT_MAX, INT_MAX]
ans = []
timer = 0
DFS Traversal:
Start DFS from node 0:

visited[0] = 1

disc[0] = low[0] = timer = 0

timer = 1

Visit node 1 from node 0:

visited[1] = 1

disc[1] = low[1] = timer = 1

timer = 2

Visit node 2 from node 1:

visited[2] = 1

disc[2] = low[2] = timer = 2

timer = 3

Visit node 0 from node 2 (back edge to parent):
Since node 0 is visited and is the parent, back edge is detected.
Update low[2] = min(low[2], disc[0]) = min(2, 0) = 0
After finishing node 2:

low[1] = min(low[1], low[2]) = min(1, 0) = 0
Node 2 does not form a bridge because low[2] <= disc[1].
Visit node 0 from node 1 (back edge to parent):

This is ignored as it's the parent of node 1.
Visit node 3 from node 1:

visited[3] = 1
disc[3] = low[3] = timer = 3
timer = 4
After finishing node 3, low[1] = min(low[1], low[3]) = min(0, 3) = 0
Since low[3] > disc[1], we have a bridge between nodes 1 and 3.
Add bridge to ans: ans = [[3, 1]]
After finishing node 1:

low[0] = min(low[0], low[1]) = min(0, 0) = 0
No bridge between nodes 0 and 1 as low[1] <= disc[0].
Result:

The bridge found is between nodes 1 and 3, and ans = [[3, 1]].
Conclusion:
The dry run shows that the only critical connection (bridge) in the graph is the edge between nodes 1 and 3. The rest of the edges are part of cycles and thus do not form bridges.

Final result: [[3, 1]].










