//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<int, pair<int, int>>> v;  // Vector to store node values with their row and column indices
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});  // Root node with initial row and column (0, 0)

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto front = q.front();
                q.pop();

                TreeNode* node = front.first;
                int row = front.second.first;
                int col = front.second.second;

                v.push_back({node->val, {col, row}}); 

                if (node->left) {
                    q.push({node->left, {row + 1, col - 1}});
                }
                if (node->right) {
                    q.push({node->right, {row + 1, col + 1}});
                }
            }
        }

        // Sort the vector by column first, then by row, and finally by node value
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            if (a.second.first != b.second.first)  // Compare by column
                return a.second.first < b.second.first;
            if (a.second.second != b.second.second)  // Compare by row
                return a.second.second < b.second.second;
            return a.first < b.first;  // Compare by node value
        });

        vector<vector<int>> res;
        vector<int> temp;

        int currCol = v[0].second.first; 

        for (int i = 0; i < v.size(); i++) {
            int col = v[i].second.first;  
            if (col != currCol) {
                res.push_back(temp);  
                temp.clear();  
                currCol = col;  
            }
            temp.push_back(v[i].first);  
        }

        res.push_back(temp);  // Add the last column's nodes

        return res;
    }
};


