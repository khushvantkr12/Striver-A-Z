class Solution {
public:
  int height (TreeNode * root,bool &ans)
    {
        if(!root) return 0;
        int lh = height(root->left,ans);
        int rh = height(root->right,ans);
        
        if(abs(lh-rh) > 1){
            return ans=0;
        }
    
        
        return max(lh,rh)+1;//to calculate the height of left and right subtree...
    }
    bool isBalanced(TreeNode* root) {
         bool ans=1;
        height(root,ans);
        return ans;
        
    }
};