class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //using stack
        stack<TreeNode*>st;
        vector<int>ans;
        TreeNode* x=root;
        while(true){
           
            if(x!=NULL){
                st.push(x);
                x=x->left;
            }else{
                if(st.empty()) break;
                x=st.top();
                 st.pop();
               ans.push_back(x->val);
               x=x->right;
            }
        }
        return ans;
    }
};