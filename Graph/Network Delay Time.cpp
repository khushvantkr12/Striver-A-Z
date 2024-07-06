//https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);//1 based indexing
        for(auto it:times){
            int x=it[0];
            int y=it[1];
            int wt=it[2];
            adj[x].push_back({y,wt});
        }
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       pq.push({0,k});
      
    vector<int>result(n+1,INT_MAX);
    result[k]=0;
    
    while(!pq.empty()){
        int wt=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        
        for(auto u:adj[node]){
            int curr_node=u.first;
            int curr_wt=u.second;
            if(curr_wt+wt<result[curr_node]){
                pq.push({curr_wt+wt,curr_node});
                result[curr_node]=curr_wt+wt;
            }
        }
    }
    int maxi=INT_MIN;
    for(int i=1; i<result.size(); i++){
        if(result[i]==INT_MAX){
            return -1;
        }
      maxi=max(maxi,result[i]);
    }
    return maxi;
    }
};