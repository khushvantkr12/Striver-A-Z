//https://leetcode.com/problems/recover-binary-search-tree/description/

//TC-O(2N)+O(NLOGN)-->sorting+first find inorder then comparing
//SC-O(N)

class Solution {
public:
    void solve(vector<int>& ans, TreeNode* root) {
        // Base case
        if (root == nullptr) {
            return;
        }
        solve(ans, root->left);
        ans.push_back(root->val);
        solve(ans, root->right);
    }
    
    void kittu(int& i, TreeNode* root, const vector<int>& ans) {
        // Base case
        if (root == nullptr) {
            return;
        }

        kittu(i, root->left, ans);
        if (root->val != ans[i]) {
            root->val = ans[i];
        }
        i++;
        kittu(i, root->right, ans);
    }

    void recoverTree(TreeNode* root) {
        vector<int> ans;
        solve(ans, root);
        sort(ans.begin(), ans.end());  // Now this is inorder
        
        int i = 0;
        kittu(i, root, ans);
    }
};

