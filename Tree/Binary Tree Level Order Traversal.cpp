
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
if(root==NULL){
            return ans;
        }
        while(!q.empty()){
            int sz=q.size();
            vector<int>temp;
             
              while(sz--){
            TreeNode* x=q.front();
            temp.push_back(x->val);
             q.pop();

            if(x->left)
                q.push(x->left);
            
             if(x->right)
                q.push(x->right);
            
        }
        ans.push_back(temp);
        }
     return ans;
    }
};