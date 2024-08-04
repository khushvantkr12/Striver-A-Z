//https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        map<int, int> mp; // level, node data
        queue<pair<int, Node*>> q;
        vector<int> ans;

        if (root == NULL) {
            return ans;
        }

        q.push({0, root});

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                Node* x = q.front().second;
                int y = q.front().first;
                q.pop();

                if (mp.find(y) == mp.end()) {//mtlb jo jm khoj rhe h wo hmko abhi tk nhi mila hai
                    mp.insert({y, x->data});
                }

                if (x->left) {
                    q.push({y-1, x->left});
                }
                if (x->right) {
                    q.push({y+1, x->right});
                }
            }
        }

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};