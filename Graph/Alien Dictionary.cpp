//https://www.geeksforgeeks.org/problems/alien-dictionary/1

class Solution{
public:
    string findOrder(string dict[], int N, int K) {
        // Adjacency list for graph
        vector<vector<int>> adj(K);
        vector<int> indegree(K, 0);

        // Build the graph
        for (int i = 0; i < N - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];

            for (int j = 0; j < word1.size(); j++) {
                if (word1[j] != word2[j]) {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    indegree[word2[j] - 'a']++;
                    break;
                }
            }
        }

        // Queue for topological sort
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Topological sort
        string result;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr + 'a');//This converts the index back to the corresponding character in the alphabet.

            for (auto neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return result;
    }
};
