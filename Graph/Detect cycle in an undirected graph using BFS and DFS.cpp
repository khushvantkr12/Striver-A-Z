//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

//USING BFS
class Solution {
  public:
  bool detectCycle(vector<int> adj[] , vector<bool>& vis, int src)
    {
        queue<pair<int,int>>q;
        q.push({src,-1});
        vis[src]=true;
        
        while(!q.empty())
        {
            int node=q.front().first, parent=q.front().second;
            q.pop();
            
            for(auto x: adj[node])
            {
                if(!vis[x])
                {
                    vis[x]=true;
                    q.push({x,node});
                }
                else if(x!=parent) 
                    return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
         vector<bool>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(! vis[i])
            {
                if(detectCycle(adj,vis,i)) return true;
            }
        }
        return false;
    }
};

//USING DFS

class Solution {
  public:
    bool isCycle(vector<int> adj[],int u,vector<bool>&visited,int parent){
        //base
        
        
        visited[u]=true;
        for(auto v:adj[u]){
            if(v!=parent&&visited[v]==true){
                return true;
            }
          if(v==parent){
              continue;
          }
          if(isCycle(adj,v,visited,u)){
              return true;
          }
            
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(isCycle(adj,i,visited,-1)){
                return true;
            }
            }
        }
        return false;
    }
};

//DRY RUN
Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1

Graph Representation
Given:

V = 5 (number of vertices)
E = 5 (number of edges)
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}
This adjacency list can be visualized as:

Node 0 is connected to Node 1
Node 1 is connected to Nodes 0, 2, and 4
Node 2 is connected to Nodes 1 and 3
Node 3 is connected to Nodes 2 and 4
Node 4 is connected to Nodes 1 and 3
Dry Run of the Code
Initialization:

visited = [false, false, false, false, false]
Starting the outer loop in isCycle function:

i = 0
if (!visited[0]) is true
Call isCycle(adj, 0, visited, -1)
First Call to isCycle: isCycle(adj, 0, visited, -1)

visited[0] = true => visited = [true, false, false, false, false]
Loop through adj[0] (which is {1}):
v = 1
if (v != parent && visited[v] == true) is false
Call isCycle(adj, 1, visited, 0)
Second Call to isCycle: isCycle(adj, 1, visited, 0)

visited[1] = true => visited = [true, true, false, false, false]
Loop through adj[1] (which is {0, 2, 4}):
v = 0
if (v != parent && visited[v] == true) is false (since v == parent)
Continue to next iteration
v = 2
if (v != parent && visited[v] == true) is false
Call isCycle(adj, 2, visited, 1)
Third Call to isCycle: isCycle(adj, 2, visited, 1)

visited[2] = true => visited = [true, true, true, false, false]
Loop through adj[2] (which is {1, 3}):
v = 1
if (v != parent && visited[v] == true) is false (since v == parent)
Continue to next iteration
v = 3
if (v != parent && visited[v] == true) is false
Call isCycle(adj, 3, visited, 2)
Fourth Call to isCycle: isCycle(adj, 3, visited, 2)

visited[3] = true => visited = [true, true, true, true, false]
Loop through adj[3] (which is {2, 4}):
v = 2
if (v != parent && visited[v] == true) is false (since v == parent)
Continue to next iteration
v = 4
if (v != parent && visited[v] == true) is false
Call isCycle(adj, 4, visited, 3)
Fifth Call to isCycle: isCycle(adj, 4, visited, 3)

visited[4] = true => visited = [true, true, true, true, true]
Loop through adj[4] (which is {1, 3}):
v = 1
if (v != parent && visited[v] == true) is true (since visited[1] == true and v != parent)
Cycle detected, return true
The cycle detection bubbles up through the recursive calls:

isCycle(adj, 3, visited, 2) returns true
isCycle(adj, 2, visited, 1) returns true
isCycle(adj, 1, visited, 0) returns true
isCycle(adj, 0, visited, -1) returns true
Finally, isCycle(V, adj) returns true.
