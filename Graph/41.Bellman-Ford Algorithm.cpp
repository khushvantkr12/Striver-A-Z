//https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        //here we do not need to make adjacency list.because loop runs V-1 times
        
        vector<int>result(V,1e8);
        result[S]=0;
        for(int i=0; i<=V-1; i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int w=it[2];
                if(result[u] != 1e8&&result[u]+w<result[v]){
                    result[v]=result[u]+w;
                }
            }
        }
        //negative cycle detection
        for(int i=V; i>0; i--){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int w=it[2];
                if(result[u] != 1e8&&result[u]+w<result[v]){
                   return {-1};
                }
            }
            break;
        }
        return result;
    }
};
