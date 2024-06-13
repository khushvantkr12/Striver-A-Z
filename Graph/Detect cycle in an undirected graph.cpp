//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
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