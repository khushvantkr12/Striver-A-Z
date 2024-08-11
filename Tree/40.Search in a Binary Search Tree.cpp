//https://leetcode.com/problems/search-in-a-binary-search-tree/description/

TreeNode* solve(TreeNode* root,int val){
     
     if( root==NULL){
         return NULL;
     }
     if(root->val==val){
         return root;
     }
     if(root->val < val){
     return solve(root->right,val);
     }
    return solve(root->left,val);
     
 }
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
       return solve(root,val);
       
    }
};