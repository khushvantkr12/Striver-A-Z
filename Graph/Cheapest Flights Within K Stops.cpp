//https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

//here if you using priority_queue it will passes 53/54 testcases..using queue is best approach

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adj[u].push_back({v, w});
        }

       
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, k + 1}});

        vector<int> res(n, INT_MAX); 
        res[src] = 0;

        
        while (!q.empty()) {
            int wt = q.front().first;
            int node = q.front().second.first;
            int stops_left = q.front().second.second;
            q.pop();

           if(stops_left<=0){
            continue;
           }
            for (auto& u : adj[node]) {
                int next_node = u.first;
                int weight = u.second;
               
                int new_cost = wt + weight;
                if (new_cost < res[next_node] ) {
                    res[next_node] = new_cost;
                    q.push({new_cost, {next_node, stops_left - 1}});
                }
            }
        }

        return res[dst] == INT_MAX ? -1 : res[dst];
    }
};
