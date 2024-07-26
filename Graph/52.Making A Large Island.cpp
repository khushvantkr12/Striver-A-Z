//https://leetcode.com/problems/making-a-large-island/description/

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

        if (size[x_parent] > size[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        } else {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

class Solution {
public:
    bool isCheck(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
         //edge case,,if all grid are 1
         int count=0;
         for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
         }
         if(count==n*n){
            return count;
         }
        // Connect all adjacent 1's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    int newdx = i + dx[k];
                    int newdy = j + dy[k];
                    if (isCheck(newdx, newdy, n) && grid[newdx][newdy] == 1) {
                        int node = i * n + j;
                        int adjnode = newdx * n + newdy;
                        dsu.Union(node, adjnode);
                    }
                }
            }
        }

        // Now we have to replace 0 with 1 and check which gives the largest island
        int mx = 0;
        

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                set<int> st; // to store unique connected numbering to his parent
                for (int k = 0; k < 4; k++) {
                    int newdx = i + dx[k];
                    int newdy = j + dy[k];
                    if (isCheck(newdx, newdy, n) && grid[newdx][newdy] == 1) {
                        st.insert(dsu.find(newdx * n + newdy));
                    }
                }
                // Calculate size
                int size = 1; // we are considering this 0 to 1
                for (auto it : st) {
                    size += dsu.getSize(it);
                }
                mx = max(mx, size);
            }
        }
        return mx;
    }
};
