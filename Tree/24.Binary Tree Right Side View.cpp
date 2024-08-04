//https://leetcode.com/problems/binary-tree-right-side-view/description/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        queue<pair<int, TreeNode*>> q;
        stack<pair<int, int>> st;
        vector<int> ans;

        q.push({0, root});

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int x = q.front().first;
                TreeNode* y = q.front().second;
                q.pop();

                 if(st.empty() || st.top().first!=x){
                    st.push({x, y->val});
                 }

              
                if (y->right) {
                    q.push({x + 1, y->right});
                }
                
                if (y->left) {
                    q.push({x + 1, y->left});
                }
            }
        }

       
        while (!st.empty()) {
            ans.push_back(st.top().second);
            st.pop();
        }
        reverse(ans.begin(), ans.end());  

        return ans;
    }
};
