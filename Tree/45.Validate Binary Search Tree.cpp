//https://leetcode.com/problems/validate-binary-search-tree/description/

//T.C-O(n)
//SC-O(n)

class Solution {
public:
//INORDER
    void solve(TreeNode* root, vector<int>&ans){
        if(root==NULL){
            return;
        }
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);

        for(int i=0; i<ans.size()-1; i++){
            if(ans[i]>=ans[i+1]){
             return false;
            }
        }
        return true;
    }
};

//T.C-O(n)
//SC-O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root,long mini,long maxi){
        if(root==NULL){
            return true;
        }

        if(root->val<=mini || root->val>=maxi){
            return false;
        }
       bool x= solve(root->left,mini,root->val);
       bool y= solve(root->right,root->val,maxi);
        return x&&y;
    }
    bool isValidBST(TreeNode* root) {
        //key idea is maintain range [INT_MIN,INT_MAX];..when any root->val is out of range return false
    
       return solve(root,LLONG_MIN,LLONG_MAX);
    }
};
