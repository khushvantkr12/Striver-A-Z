class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //using stack
        stack<TreeNode*>st;
        vector<int>ans;
        st.push(root);
        if(root==NULL){
            return ans;
        }
        while(!st.empty()){
           TreeNode* x=st.top();
           ans.push_back(x->val);
           st.pop();

            if(x->right)
           st.push(x->right);
            if(x->left)
           st.push(x->left);
        
        }
        return ans;
    }
};