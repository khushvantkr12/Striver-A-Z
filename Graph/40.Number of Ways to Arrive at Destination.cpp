//https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

class Solution {
public:
    int MOD = 1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : roads) {
            int x = it[0];
            int y = it[1];
            int wt = it[2];
            adj[x].push_back({y, wt});
            adj[y].push_back({x, wt});
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});

        vector<long long> result(n, LLONG_MAX);
        result[0] = 0;
        vector<int> ways(n, 0);
        ways[0] = 1;

        while (!pq.empty()) {
            long long wt = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for (auto u : adj[node]) {
                long curr_node = u.first;
                long curr_wt = u.second;
                if (curr_wt + wt < result[curr_node]) {
                    pq.push({curr_wt + wt, curr_node});
                    result[curr_node] = curr_wt + wt;
                    //suppose kro ki tm first time aaye ho ways[n-1] pe aur tum jaha se aaye ho waha pe 3 hai to tm 3 ko direct ways[n-1] me daaloge na..isiliye ye likhe hai
                    ways[curr_node] = ways[node];
                } else if (curr_wt + wt == result[curr_node]) {
                    ways[curr_node] = (ways[curr_node] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};