//https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class Solution 
{
public:

    //Mark connected computers as visited in vis vector by using dfs.
    void dfsConnectedComputers(int node,vector<vector<int>>&adj, vector<int> &visited)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
                dfsConnectedComputers(it, adj, visited);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int edges = connections.size();
        if(edges<n-1)
         return -1; //Minimum no. of egdes should be (n-1).

        vector<vector<int>>adj(n);
        for(auto it:connections) //creating adjacency list
        {
            adj[it[0]].push_back(it[1]);//{adj[0]=(1,2,3),adj[1]=(0,2,3)}
            adj[it[1]].push_back(it[0]);//{adj[2]=(0,1), adj[3]=(0,1)}
        }

        vector<int> visited(n,0);
        int disconnected=0;
        
        for(int i=0; i<n; i++) //count disconnected computers
        {
            if(!visited[i]) 
            {
                disconnected++;
                dfsConnectedComputers(i, adj, visited);
            }
        }
    
        return disconnected-1;
    }
};