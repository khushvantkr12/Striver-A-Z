//https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
 void kSmall(TreeNode* root, vector<int>&ans,int k){
     if(!root){
         return ;
     }
     kSmall(root->left,ans,k);
     ans.push_back(root->val);
     kSmall(root->right,ans,k);
 }
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        kSmall(root,ans,k);
        return ans[k-1];
    }
};