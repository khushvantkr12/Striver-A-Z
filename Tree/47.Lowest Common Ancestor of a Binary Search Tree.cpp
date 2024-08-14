//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/


class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        //base
        //last intersection point (b/w p and q) traverse from last is called LCA
        if(root == NULL){
            return NULL;
        }

        if(root->val > p->val && root->val > q->val){
            return solve(root->left, p, q);
        } else if(root->val < p->val && root->val < q->val){
          return  solve(root->right, p, q);
        } else if(root->val>=p->val && root->val<=q->val){
            return root;
        }else if(root->val<=p->val && root->val>=q->val){
            return root;
        }
        return 0;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};