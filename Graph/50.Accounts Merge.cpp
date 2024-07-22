//https://leetcode.com/problems/accounts-merge/

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
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> mp; // map to track email to account index

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.find(accounts[i][j]) == mp.end()) {
                    mp[accounts[i][j]] = i;
                } else {
                    dsu.Union(i, mp[accounts[i][j]]);
                }
            }
        }
        //ab hmko us mail ko bhi same parent ko jodna hai jiska mail already kahi present hai..."John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],for this tc we have to merge this john00@mail.com with index 0;
        vector<string> mergemail[n];
        for (auto it : mp) {
            string mail = it.first;
            int node = dsu.find(it.second);//suppose it.second=3 aaya lekin 3 jo hai wo 1 ka child hai..so yaha pe node=1 hojayega..
            mergemail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergemail[i].size() == 0) {
                continue;
            }
            // sort
            sort(mergemail[i].begin(), mergemail[i].end());
            vector<string> temp;
            // pushing name
            temp.push_back(accounts[i][0]);
            // now push emails
            for (auto it : mergemail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
