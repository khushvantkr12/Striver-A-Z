//https://leetcode.com/problems/count-complete-tree-nodes/description/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        while(!q.empty()){
          int sz=q.size();
          while(sz--){
            TreeNode* x=q.front();
            q.pop();
            count++;
            if(x->left){
                q.push(x->left);
            }
            if(x->right){
                q.push(x->right);
            }
          }
          
        }
        return count;
    }
};