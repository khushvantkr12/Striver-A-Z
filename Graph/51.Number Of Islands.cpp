//https://www.geeksforgeeks.org/problems/number-of-islands/1

class DSU {
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (size[x_parent] >= size[y_parent]) { // changed to >=
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        } else {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }
};

class Solution {
public:
    bool isSolve(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DSU dsu(n * m); // corrected to n*m

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> ans;

        for (int i = 0; i < operators.size(); i++) {
            int x = operators[i][0];
            int y = operators[i][1];

            if (visited[x][y] == true) {
                ans.push_back(count);
                continue;
            }
            visited[x][y] = true;
            count++;

            for (int k = 0; k < 4; k++) {
                int node = x + dx[k];
                int adjnode = y + dy[k];

                if (isSolve(node, adjnode, n, m) && visited[node][adjnode] == true) {
                    int nodeno = x * m + y; 
                    int adjnodeno = node * m + adjnode; 
                    // check if already connected
                    if (dsu.find(nodeno) != dsu.find(adjnodeno)) {
                        count--;
                        dsu.Union(nodeno, adjnodeno);
                    }
                }
            }
            ans.push_back(count);
        }

        return ans;
    }
};