class Solution {
public:
    int solve(TreeNode* root,vector<int>&ans){
        //base
        if(root==NULL){
            return 0;
        }
    
    int lh=solve(root->left,ans);
    int rh=solve(root->right,ans);
     ans.push_back(lh+rh);
    return max(lh,rh)+1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        int maxi=*max_element(ans.begin(),ans.end());
        return maxi;
    }
};