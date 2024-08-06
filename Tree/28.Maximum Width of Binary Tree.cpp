//https://leetcode.com/problems/maximum-width-of-binary-tree/description/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        long long maxi=0;
        while(!q.empty()){
            long long sz=q.size();
            long long maxidx=q.back().second;
            long long minidx=q.front().second;

            while(sz--){
                TreeNode* x=q.front().first;
                long long y=q.front().second;
                q.pop();

                if(x->left){
                    q.push({x->left,2*y+1});
                }
                if(x->right){
                    q.push({x->right,2*y+2});
                }
            }
            maxi=max(maxi,maxidx-minidx+1);
        }
        return maxi;
    }
};