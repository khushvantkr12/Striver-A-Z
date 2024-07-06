//https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

//here if you using priority_queue it will passes 53/54 testcases..using queue is best approach
//here the code of DIJKSTRA algo but it passes 53/54 cases.
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : flights) {
            int x = it[0];
            int y = it[1];
            int wt = it[2];
            adj[x].push_back({y, wt});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {src, k + 1}}); // Start from src with k+1 stops

        vector<int> res(n, INT_MAX);
        res[src] = 0;

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int K = pq.top().second.second;
            pq.pop();
              if(K<=0){
                continue;
              }
           
                for (auto u : adj[node]) {
                    int curr_node = u.first;
                    int curr_wt = u.second;

                    int new_cost = wt + curr_wt;
                    if (new_cost < res[curr_node]) {
                        pq.push({new_cost, {curr_node, K - 1}});
                        res[curr_node] = new_cost;
                    }
                
            }
        }

        return res[dst] == INT_MAX ? -1 : res[dst];
    }
};

//here is BFS solution..it passes all TC..with queue
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
