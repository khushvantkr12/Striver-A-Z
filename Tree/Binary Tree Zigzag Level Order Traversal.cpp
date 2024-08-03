class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        int count=0;
        while(!q.empty()){
            vector<int>temp;
            int sz=q.size();
            while(sz--){
             TreeNode* x=q.front();
             q.pop();
             temp.push_back(x->val);

             if(x->left!=NULL){
                q.push(x->left);
             }
              if(x->right!=NULL){
                q.push(x->right);
             }
            }
            count++;
            if(count%2==0){
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }else{
                ans.push_back(temp);
            }
        }
        return ans;
    }
};