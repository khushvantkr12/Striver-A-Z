TC-O(m^v)

class Solution {
  public:
    bool isSafe(int node,vector<vector<int>>&adj,vector<int>&color,int i){
        for(auto it:adj[node]){
            //adjacent node already have this color
            if(color[it]==i){
                return false;
            }
        }
        return true;
    }
    bool solve(int node,int v,vector<pair<int, int>>& edges,int m,vector<vector<int>>&adj,vector<int>&color){
        //base case
        if(node==v){
            //we can reach last node
            return true;
        }
        
        
        for(int i=1; i<=m; i++){
            if(isSafe(node,adj,color,i)){
                color[node]=i;
                //suppose if you reach last it means you successfully colored all the nodes then return true
                if(solve(node+1,v,edges,m,adj,color)) return true;
                //backtrack
                color[node]=0;
            }
        }
        
        return false;
        
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        //approach is:
        //start with node 0  and check whether the node is color or not if not then color the node is best possible way
        //for every node try all possible color
        //suppose if you reach last it means you successfully colored all the nodes then return true
        vector<vector<int>> adj(v);  // 1-based indexing
        for (auto edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        vector<int>color(v,0);
        return solve(0,v,edges,m,adj,color);
    }
};