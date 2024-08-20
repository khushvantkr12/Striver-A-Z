//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

//TC-O(N)
//SC-O(N)
class Solution {
public:
    void solve(vector<int>&ans,TreeNode* root, int k){
        if(root==NULL){
            return ;
        }
        solve(ans,root->left,k);
        ans.push_back(root->val);
        solve(ans,root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
         solve(ans,root,k);
        int i=0,j=ans.size()-1;
        while(i<j){
            if(ans[i]+ans[j]==k){
                return true;
                
            }else if(ans[i]+ans[j]>k){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};