class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        stack<TreeNode *> s1,s2;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* x=s1.top();
            s1.pop();
            s2.push(x);
            if(x->left!=NULL){
                s1.push(x->left);
            }
            if(x->right!=NULL){
                s1.push(x->right);
            }
        }
        while(!s2.empty()){
            res.push_back(s2.top()->val);
            s2.pop();
        }
        return res;
    }
};