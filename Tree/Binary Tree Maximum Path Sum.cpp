class Solution {
public:
    int solve(TreeNode* root,int& maxi){
        if(root==NULL){
            return 0;
        }
        int left=max(0,solve(root->left,maxi));//minus wala ko 0 me convert kar dega
        int right=max(0,solve(root->right,maxi));
        //int maxi=INT_MIN;
        maxi=max(maxi,left+right+root->val);

        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
       
       int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;


    }
};