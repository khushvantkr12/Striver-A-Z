//https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       vector<vector<int>>adj(graph.size());
       vector<int>indegree(graph.size(),0);

       for(int i=0; i<graph.size(); i++){
           for(auto it:graph[i]){
               adj[it].push_back(i);//push in reverse dirn
               indegree[i]++;
           }
       }
        vector<int>ans;
       queue<int>q;
       for(int i=0; i<graph.size(); i++){
           if(indegree[i]==0){
               q.push(i);
           }
       }
           while(!q.empty()){
               int u=q.front();
               q.pop();
              ans.push_back(u);

            for(auto it:adj[u]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
                
            }
           }
       
       sort(ans.begin(),ans.end());
       return ans;
    }
};