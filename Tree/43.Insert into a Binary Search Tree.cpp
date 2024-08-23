//https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

class Solution {
public:
    TreeNode* solve(TreeNode* root, int val){
        if(root == NULL){
            return new TreeNode(val);
        }

       
        if(root->val > val){
            root->left = solve(root->left, val);
        } 
       
        else {
            root->right = solve(root->right, val);
        }

        
        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
       return solve(root, val);
    }
};