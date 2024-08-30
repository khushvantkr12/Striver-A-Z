//not a striver sheet ques..but good ques

//https://leetcode.com/problems/modify-graph-edge-weights/description/

//TC-O(E*(ELOGV))
//SC-O(E+V)

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {

        vector<vector<pair<int,int>>> adj(n);

        //excluding edges with weight = -1
        for(auto e: edges){
            if(e[2]!=-1){
                adj[e[0]].push_back({e[1],e[2]});
                adj[e[1]].push_back({e[0],e[2]});
            }
        }

        //Dijkstra for shortest path
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,source});
        vector<int> dis(n,1e9);
        dis[source]=0;
        while(!q.empty()){
            int curr_dis=q.top().first;
            int u=q.top().second;
            q.pop();
            if(u==destination){
                break;
            }
            for(auto nbr : adj[u]){
                int v=nbr.first;
                int wt=nbr.second;
                if(curr_dis+wt<dis[v]){
                    dis[v]=curr_dis+wt;
                    q.push({dis[v],v});
                }
            }
        }

        //if shortest path < target , then return empty array
        if(dis[destination]<target){
            return {};
        }

        //if shortest path is equal to target
        if(dis[destination]==target){
            for(auto &e : edges){
                if(e[2]==-1){
                    //why not e[2]=1?because if you do then shortest path is less than target...
                    e[2]=1e9;
                }
            }
            return edges;
        }

        //case: dis[destination]>target
        // Now changing weight of each edge with weight -1 to 1 one by one and trying to get shortest path
        for(int i=0 ; i<edges.size() ; i++){
            auto &e=edges[i];
            if(e[2]==-1){

                //change weight to 1
                e[2]=1;
                adj[e[1]].push_back({e[0],1});
                adj[e[0]].push_back({e[1],1});
                while(!q.empty()){
                    q.pop();
                }

                //Dijkstra 
                q.push({0,source});
                vector<int> dis(n,1e9);
                dis[source]=0;
                while(!q.empty()){
                    int curr_dis=q.top().first;
                    int u=q.top().second;
                    q.pop();
                    if(u==destination){
                        break;
                    }
                    for(auto nbr : adj[u]){
                        int v=nbr.first;
                        int wt=nbr.second;
                        if(curr_dis+wt<dis[v]){
                            dis[v]=curr_dis+wt;
                            q.push({dis[v],v});
                        }
                    }
                }

                //adding appropriate weight to get target
                if(dis[destination]<=target){
                    e[2]+=target-dis[destination];
                
                    //rest edges with weight=-1 set to 1e9
                    for(int j=i+1 ; j<edges.size() ; j++){
                        if(edges[j][2]==-1){
                            edges[j][2]=1e9;
                        }
                    }

                    return edges;
                }
            }
        }

        return {};
    }
};