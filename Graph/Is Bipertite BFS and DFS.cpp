//https://leetcode.com/problems/is-graph-bipartite/description/

//USING DFS
class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& color,int currcolor) {
        color[u]=currcolor;
        for (auto v : graph[u]) {
            //never coloured
            if (color[v] == -1) {
                color[v] = !currcolor;
                 dfs(v, graph, color,!currcolor);
                  
                 
            }   
            if (color[v] == color[u]) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 indicates that the node has not been colored yet

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) { 
                if (!dfs(i, graph, color,1)) {
                    return false;
                }
            }
        }
        return true;
    }
};

//USING BFS
class Solution {
private :
    bool bfs(int c,int s,vector<int>& color , vector<vector<int>>& graph){
          queue<int> q;
          q.push(s);

          while(!q.empty()){
              int node = q.front();
              q.pop();
              for(auto it:graph[node]){

                  if(color[it] == -1){
                      color[it] = !color[node];
                      q.push(it);
                  }
                  else if(color[it] == color[node])
                   return false;
              }
          }

        return true;  
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

          int n = graph.size();
          vector<int> color(n,-1);

           for(int i=0;i<n;i++){
               if(!bfs(0,i,color,graph))
                return false;
           }

        return true;
    }
};