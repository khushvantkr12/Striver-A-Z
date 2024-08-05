//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        //base
       if(root==NULL || root==p || root==q){
        return root;
       }
     TreeNode* left=solve(root->left,p,q);
     TreeNode* right=solve(root->right,p,q);
     if(left==NULL){
        return right;
     }else if(right==NULL){
        return left;
     }
     //agar dono hi null nhi hai to root return karo..(found result)
     return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
      
    }
};