//https://leetcode.com/problems/course-schedule/description/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //DIRECTED GRAPH(TOPO SORT)
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto it: prerequisites){
            int x=it[0];
            int y=it[1];
            adj[y].push_back(x);
            indegree[x]++;
        }
        vector<int>result;
        queue<int>q;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            result.push_back(x);
            for(auto u:adj[x]){
                indegree[u]--;
                if(indegree[u]==0){
                    q.push(u);
                }
            }
        }
        if(result.size()==numCourses){
            return true;
        }
        return false;
    }
};